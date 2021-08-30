#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n;
  cin >> n;
  ll x[n], y[n];
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
  }

  ll tot = 0;
  for (int i = 0; i < n - 1; i++)
  {
    tot += (x[i] * y[i + 1]);
  }

  for (int i = 0; i < n - 1; i++)
  {
    tot -= (x[i + 1] * y[i]);
  }
  tot += (x[n - 1] * y[0]);
  tot -= (y[n - 1] * x[0]);
  cout << abs(tot) << endl;
}