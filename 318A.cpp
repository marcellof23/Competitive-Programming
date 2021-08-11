#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll n, k;
  cin >> n >> k;
  ll total = 0;
  if (n % 2 == 1)
  {
    total = n / 2 + 1;
  }
  else
  {
    total = n / 2;
  }
  if (k <= total)
  {
    cout << 1 + 2 * (k - 1) << endl;
  }
  else
  {
    cout << 2 * (k - total) << endl;
  }
}