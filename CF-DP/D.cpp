#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e5 + 5;
ll a[maxN], t[maxN];
ll prefsum[maxN];

int main()
{
  ll k, n;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> t[i];
  }

  prefsum[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    if (t[i])
      prefsum[i] = prefsum[i - 1] + a[i];
    else
      prefsum[i] = prefsum[i - 1];
  }

  ll tot = -1;
  ll curr = 0;
  for (int i = 0; i < k; i++)
  {
    curr += a[i];
  }

  for (int i = 1; i < n - k + 2; i++)
  {
    curr = curr - a[i - 1] + a[i + k - 1];
    tot = max(tot, curr + prefsum[i - 1] + prefsum[n] - prefsum[i + k - 1]);
  }

  // for (int i = 0; i < n; i++)
  // {
  //   cout << prefsum[i] << endl;
  // }
  cout << tot << endl;
}