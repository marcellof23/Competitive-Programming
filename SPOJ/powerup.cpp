#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binary_expo(ll a, ll b, ll p)
{
  ll res = 1;
  a = a % p;
  while (b > 0)
  {
    if (b & 1)
    {
      res = (res * a) % p;
    }

    b = b >> 1;
    a = (a * a) % p;
  }
  return res;
}

int main()
{
  int a, b, c;
  ll mods = 1e9 + 7;
  while (true)
  {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
    {
      break;
    }
    if (c == 0)
    {
      cout << a % mods << endl;
      continue;
    }
    if (b == 0)
    {
      cout << 1 << endl;
      continue;
    }
    if (a % mods == 0)
    {
      cout << 0 << endl;
      continue;
    }

    ll res1 = binary_expo(b, c, mods - 1);
    ll res2 = binary_expo(a, res1, mods);
    cout << res2 << endl;
  }
}