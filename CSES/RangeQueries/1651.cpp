#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;

int n, q, segt[4 * MAXN], lazy[4 * MAXN], arr[MAXN];

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
    segt[v] = 0;
  }
}

void push(int v)
{
  segt[v * 2] += lazy[v];
  lazy[v * 2] += lazy[v];
  segt[v * 2 + 1] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] = 0;
}

int sum(int v, int tl, int tr, int l, int r)
{
  if (tr < l || tl > r)
  {
    return 0;
  }
  if (l <= tl && r >= tr)
  {
    return segt[v];
  }
  push(v);

  int tm = (tl + tr) / 2;
  return sum(2 * v, tl, tm, l, r) + sum(2 * v + 1, tm + 1, tr, l, r);
}

void update(int v, int tl, int tr, int l, int r, int newval)
{
  if (tr < l || tl > r)
  {
    return;
  }
  if (l <= tl && r >= tr)
  {
    segt[v] += newval;
    lazy[v] += newval;
  }
  else
  {
    push(v);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, r, newval);
    update(2 * v + 1, tm + 1, tr, l, r, newval);
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
      int l, r, val;
      cin >> l >> r >> val;
      --l;
      --r;
      update(1, 0, n - 1, l, r, val);
    }
    else
    {
      int l;
      cin >> l;
      --l;
      cout << sum(1, 0, n - 1, l, l) << endl;
    }
  }
}