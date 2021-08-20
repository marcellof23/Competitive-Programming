#include <bits/stdc++.h>
#define pb push_back
#define s second
#define f first
#define pii pair<int, int>
using namespace std;
const int N = 100005;
int a[N], n, X[N], ans[N], f[N], c;
int get(int x)
{
  if (X[x])
    return X[x];
  int cnt = 0, res = 1;

  ++c;
  for (int i = 1; i <= n; i++)
  {
    if (f[a[i]] == c)
      continue;
    cnt++, f[a[i]] = c;
    if (cnt == x + 1)
    {
      f[a[i]] = ++c;
      cnt = 1;
      res++;
    }
  }

  X[x] = res;
  return res;
}
void solve(int l, int r)
{
  if (l > r)
    return;
  int L = get(l), R = get(r);
  if (L == R)
  {
    for (int i = l; i <= r; i++)
      ans[i] = L;
    return;
  }
  ans[l] = L, ans[r] = R;
  int mid = (l + r) >> 1;
  solve(l + 1, mid);
  solve(mid + 1, r);
}
int main()
{
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  c = 1;
  solve(1, n);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}