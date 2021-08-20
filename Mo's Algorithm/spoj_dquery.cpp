#include <bits/stdc++.h>
using namespace std;
#define N 30005
#define M 200005
#define A 1000005
#define BLOCK 174
int answer;

struct Query
{
  int l, r, idx;
} Q[M];

int ans[M];
int a[N];
int cnt[A];

void add(int index)
{
  cnt[a[index]++];
  if (cnt[a[index]])
    ++answer;
}

void remove(int index)
{
  cnt[a[index]--];
  if (cnt[a[index]])
    --answer;
}

bool cmp(Query f, Query s)
{
  if (f.l / BLOCK != s.l / BLOCK)
    return (f.l / BLOCK) < (s.l / BLOCK);
  return f.r < s.r;
}

int main()
{
  int n, q;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> Q[i].l >> Q[i].r;
    Q[i].idx = i;
    --Q[i].l;
    --Q[i].r;
  }
  sort(Q, Q + q, cmp);
  int currL = 0, currR = 0;
  for (int i = 0; i < q; i++)
  {
  }
}
