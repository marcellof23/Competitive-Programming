#include <bits/stdc++.h>
using namespace std;

struct node
{
  int val;
  node *l, *r;
  node() {}
  node(int _val) : l(nullptr), r(nullptr), val(_val) {}
  node(node *_l, node *_r) : l(_l), r(_r), val(0)
  {
    if (_l)
      val += _l->val;
    if (_r)
      val += _r->val;
  }
};

typedef node *pnode;

const int maxn = 1e5 + 6;
int n, a[maxn];
int lst[maxn];
pnode roots[maxn];

pnode build(int l, int r)
{
  if (l == r)
    return new node(0);
  int mid = (l + r) / 2;
  return new node(build(l, mid), build(mid + 1, r));
}

pnode update(pnode p, int l, int r, int pos)
{
  if (l == r)
    return new node(p->val + 1);
  int mid = (l + r) / 2;
  if (pos <= mid)
    return new node(update(p->l, l, mid, pos), p->r);
  else
    return new node(p->l, update(p->r, mid + 1, r, pos));
}

int query(pnode pl, pnode pr, int l, int r, int lb, int rb)
{
  if (r < lb || l > rb)
    return 0;
  if (l >= lb && r <= rb)
    return pr->val - pl->val;
  int mid = (l + r) / 2;
  return query(pl->l, pr->l, l, mid, lb, rb) + query(pl->r, pr->r, mid + 1, r, lb, rb);
}

int binser(int i, int k)
{
  int l = i, r = n, ret = i;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (query(roots[i - 1], roots[mid], 0, n, 0, i - 1) <= k)
    {
      ret = mid;
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  return ret + 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  roots[0] = build(0, n);
  memset(lst, 0, sizeof lst);
  for (int i = 1; i <= n; i++)
  {
    roots[i] = update(roots[i - 1], 0, n, lst[a[i]]);
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    int ans = 0;
    for (int l = 1; l <= n; l = binser(l, i))
      ans++;
    cout << ans << ' ';
  }
  cout << '\n';
  return 0;
}
