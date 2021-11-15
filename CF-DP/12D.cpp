#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
const int MAXN = 5e5 + 5;
ll B[MAXN], I[MAXN], R[MAXN];
ll bit[MAXN];

void update(ll i, ll x)
{
  for (; i <= n; i += (i & (-i)))
  {
    bit[i] = max(bit[i], x);
  }
  return;
}

ll maxq(ll i)
{
  ll ans = 0;
  for (; i > 0; i -= (i & (-i)))
    ans = max(ans, bit[i]);
  return ans;
}

int main()
{
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> B[i] >> I[i] >> R[i];
    bit[i] = 0;
  }
}
