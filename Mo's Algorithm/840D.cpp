#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[1000010];
ll a[1000010];
ll ans[1000010];
ll num[1000010];
ll block;
ll n, q;

void add(int x)
{
  cnt[a[x]]++;
}

void del(int x)
{
  cnt[a[x]]--;
}

ll block_size;

struct Query
{
  int l, r, k, idx;
} que[1000005];

bool cmp(Query x, Query y)
{
  if (num[x.l] == num[y.l])
    return x.r < y.r;
  else
    return num[x.l] < num[y.l];
}

mt19937 rnd(time(0));

void mos()
{
  sort(que + 1, que + q + 1, cmp);

  ll cur_l = 1;
  ll cur_r = 0;

  for (int i = 1; i <= q; i++)
  {
    while (cur_l > que[i].l)
    {
      cur_l--;
      add(cur_l);
    }
    while (cur_r < que[i].r)
    {
      cur_r++;
      add(cur_r);
    }
    while (cur_l < que[i].l)
    {
      del(cur_l);
      cur_l++;
    }
    while (cur_r > que[i].r)
    {
      del(cur_r);
      cur_r--;
    }
    ll res = (ll)2 << 32 - 1;
    for (int j = 1; j <= 100; j++)
    {
      ll tt = rnd() % (que[i].r - que[i].l + 1) + que[i].l;
      if (cnt[a[tt]] > (que[i].r - que[i].l + 1) / que[i].k)
        res = min(res, a[tt]);
    }
    if (res == (ll)2 << 32 - 1)
      ans[que[i].idx] = -1;
    else
      ans[que[i].idx] = res;
  }
  for (int i = 1; i <= q; i++)
    printf("%lld\n", ans[i]);
}

int main()
{

  cin >> n >> q;
  block = sqrt(n);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    num[i] = (i - 1) / block + 1;
  }
  for (int i = 1; i <= q; i++)
  {
    int l, r, k;
    cin >> l >> r >> k;
    Query query;
    query.l = l;
    query.r = r;
    query.k = k;
    query.idx = i;
    que[i] = query;
  }
  mos();
}