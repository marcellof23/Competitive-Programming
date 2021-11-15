#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> bit;
ll n;

void update(ll i, ll x)
{
  for (; i <= n; i += (i & (-i)))
  {
    bit[i] += x;
  }
  return;
}

ll sum(ll i)
{
  ll ans = 0;
  for (; i > 0; i -= (i & (-i)))
    ans += bit[i];
  return ans;
}

int main()
{
  ll i, k, ans = 0;
  cin >> n >> k;
  vector<ll> v(n);
  bit.resize(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<ll> a(n, 1);
  if (k >= n)
  {
    cout << 0 << "\n";
    return 0;
  }

  if (!k)
  {
    cout << n << "\n";
    return 0;
  }

  while (k--)
  {
    bit.assign(n, 0);
    for (i = 0; i < n; i++)
    {
      update(v[i], a[i]);

      a[i] = sum(v[i] - 1);

      if (!k)
      {
        ans += a[i];
      }
    }
  }
  cout << ans << endl;
}