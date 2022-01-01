#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

ll binpow(ll a, ll b)
{
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
  }
}