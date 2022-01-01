#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 5;

int n, q, segt[4 * MAXN], arr[MAXN];

void build(int v, int tl, int tr)
{
  if (tl == tr)
  {
    segt[v] = arr[tl];
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    segt[v] = max(segt[2 * v], segt[2 * v + 1]);
  }
}

void update(int v, int tl, int tr, int pos, int newval)
{
  if (tl == tr)
  {
    segt[v] -= newval;
  }
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, newval);
    else
      update(2 * v + 1, tm + 1, tr, pos, newval);
    segt[v] = max(segt[2 * v], segt[2 * v + 1]);
  }
}

int get_first(int v, int lv, int rv, int l, int r, int x)
{
  if (lv > r || rv < l)
    return -1;
  if (l <= lv && rv <= r)
  {
    if (segt[v] < x)
      return -1;
    while (lv != rv)
    {
      int mid = lv + (rv - lv) / 2;
      if (segt[2 * v] >= x)
      {
        v = 2 * v;
        rv = mid;
      }
      else
      {
        v = 2 * v + 1;
        lv = mid + 1;
      }
    }
    return lv;
  }

  int mid = lv + (rv - lv) / 2;
  int rs = get_first(2 * v, lv, mid, l, r, x);
  if (rs != -1)
    return rs;
  return get_first(2 * v + 1, mid + 1, rv, l, r, x);
}

signed main()
{
  cin >> n >> q;

  memset(arr, 0, sizeof(arr));
  memset(segt, 0, sizeof(segt));

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  build(1, 0, n - 1);

  while (q--)
  {
    int val, ans;
    cin >> val;
    ans = get_first(1, 0, n - 1, 0, n - 1, val);

    if (ans == -1)
      cout << 0 << endl;
    else
    {
      update(1, 0, n - 1, ans, val);
      cout << ans + 1 << endl;
    }
  }
}