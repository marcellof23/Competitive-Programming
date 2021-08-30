#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n;
  cin >> n;
  int t[n];
  ll total = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
    total += t[i];
  }
  sort(t, t + n);
  cout << max(total, (ll)t[n - 1] * 2) << endl;
}