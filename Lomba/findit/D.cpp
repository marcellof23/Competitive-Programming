#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mods = 1e9 + 7;

ll countDivisors(int n)
{
  int cnt = 0;
  for (int i = 1; i <= 9; i++)
  {
    if (n % i == 0)
      cnt++;
  }

  return cnt;
}

int main()
{
  int t;
  cin >> t;

  ll divisor[1069];
  for (int i = 1; i <= 1059; i++)
  {
    divisor[i] = countDivisors(i);
  }

  while (t--)
  {
    int x;
    cin >> x;
    int total = 1;
    for (int i = 1; i <= x; i++)
    {
      total = total * divisor[i] % mods;
      total %= mods;
    }
    cout << total << endl;
  }
}