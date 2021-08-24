#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll x, ll y)
{
  ll res = 1; // Initialize result

  if (x == 0)
    return 0; // In case x is divisible by p;

  while (y > 0)
  {
    // If y is odd, multiply x with result
    if (y & 1)
      res = (res * x);

    // y must be even now
    y = y >> 1; // y = y/2
    x = (x * x);
  }
  return res;
}

int main()
{
  int q;
  cin >> q;
  ll arr[19], arr2[19];
  arr2[0] = 9;
  arr[0] = 9;
  for (int i = 1; i < 19; i++)
  {
    arr2[i] = arr2[i - 1] * 10;
    arr[i] = arr2[i - 1] * (i);
  }

  while (q--)
  {
    ll k;
    cin >> k;
    ll cnt = 1;
    while (k - arr[cnt] > 0)
    {
      k -= arr[cnt];
      cnt++;
    }
    ll ans = power(10, cnt - 1) + ((k + (cnt - 1)) / cnt) - 1;
    string s = to_string(ans);
    if (!(k % cnt))
      cout << s[cnt - 1] << endl;
    else
      cout << s[(k % cnt) - 1] << endl;
  }
}