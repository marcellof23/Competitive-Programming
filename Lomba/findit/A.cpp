#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    ll total = 0;
    ll a = 1e16, b = 1e16, c = 1e16;
    if (n >= 12)
    {
      ll sums = n / 12;
      a = sums * 34 % 2022;
      n %= 12;
    }

    if (n >= 10)
    {
      ll sums = n / 10;
      b = sums * 30 % 2022;
      n %= 10;
    }

    if (n >= 8)
    {
      ll sums = n / 8;
      c = sums * 26 % 2022;
      n %= 8;
    }

    total += (min(a, min(b, c)));

    if (n < 12 && n > 9)
    {
      total += 34;
    }

    if (n < 10 && n > 7)
    {
      total += 30;
    }

    if (n < 8 && n > 0)
    {
      total += 26;
    }

    cout << total % 2022 << endl;
  }
}