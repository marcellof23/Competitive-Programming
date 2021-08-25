#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll n;
  cin >> n;
  ll total = 0, maks = 0, cnt = 0, mins = -(1e18 + 7);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    total += x;
    if (total < 0)
    {
      cnt++;
      mins = max(mins, total);
      total = 0;
    }
    // total = max(total, 0);
    maks = max(maks, total);
  }
  if (cnt == n)
  {
    cout << mins << endl;
    return 0;
  }
  cout << maks << endl;
}