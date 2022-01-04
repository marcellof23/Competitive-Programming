
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 6;

ll arr[MAXN];

struct datas
{
  ll sum, pref, suff, ans;
};

datas st[4 * MAXN];

datas combine(datas l, datas r)
{
  datas res;
  res.sum = l.sum + r.sum;
  res.pref = max(l.pref, l.sum + r.pref);
  res.suff = max(r.suff, r.sum + l.suff);
  res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
  return res;
}

datas make_datas(int val)
{
  datas res;
  res.sum = val;
  res.pref = res.suff = res.ans = max(0, val);
  return res;
}

void build(int v, int tl, int tr)
{
  if (tl == tr)
  {
    st[v] = make_datas(arr[tl]);
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    st[v] = combine(st[2 * v], st[2 * v + 1]);
  }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
  if (tl == tr)
  {
    st[v] = make_datas(new_val);
  }
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    st[v] = combine(st[v * 2], st[v * 2 + 1]);
  }
}

datas query(int v, int tl, int tr, int l, int r)
{
  if (l > r)
    return make_datas(0);
  if (l == tl && r == tr)
    return st[v];
  int tm = (tl + tr) / 2;
  return combine(query(v * 2, tl, tm, l, min(r, tm)),
                 query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main()
{
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  build(1, 0, n - 1);

  while (q--)
  {
    int k, x;
    cin >> k >> x;
    --k;
    update(1, 0, n - 1, k, x);
    datas q = query(1, 0, n - 1, 0, n - 1);
    cout << q.ans << endl;
  }
}