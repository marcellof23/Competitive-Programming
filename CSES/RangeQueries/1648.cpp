#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    segt[v] = segt[2 * v] + segt[2 * v + 1];
  }
}

int sum(int v, int tl, int tr, int l, int r)
{
  if (l > r)
  {
    return 0;
  }
  if (l == tl && r == tr)
  {
    return segt[v];
  }

  int tm = (tl + tr) / 2;
  return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int newval)
{
  if (tl == tr)
  {
    segt[v] = newval;
  }
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, newval);
    else
      update(2 * v + 1, tm + 1, tr, pos, newval);
    segt[v] = segt[2 * v] + segt[2 * v + 1];
  }
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
    int op;
    cin >> op;
    if (op == 1)
    {
      int pos, val;
      cin >> pos >> val;
      --pos;
      update(1, 0, n - 1, pos, val);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << sum(1, 0, n - 1, l, r) << endl;
    }
  }
}