#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = n + 1; i <= m; i++)
  {
    bool isPrime = true;
    for (int j = 2; j <= sqrt(m); j++)
    {
      if (i % j == 0)
      {
        isPrime = false;
      }
    }
    if (isPrime)
    {
      if (i != m)
      {
        cout << "NO" << endl;
      }
      else
      {
        cout << "YES" << endl;
      }
      return 0;
    }
  }
  cout << "NO" << endl;
}