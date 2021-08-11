#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll n;
  cin >> n;
  unordered_map<int, int> dp;
  for (int i = n; i >= 0; i--)
  {
    if (dp[i] == 0 && i != n)
    {
      continue;
    }
    int cp = i;
    while (cp != 0)
    {
      cout << cp << "e";
      int cur = cp % 10;
      cout << cur << " ";
      if (cur == 0)
      {
        cp /= 10;
        continue;
      }
      if (dp[i - cur] != 0)
      {
        dp[i - cur] = min(dp[i - cur], dp[i] + 1);
      }
      else
      {
        dp[i - cur] = dp[i] + 1;
      }
      //cout << i - cur << "a" << dp[i - cur] << "e";
      cp /= 10;
      //cout << cp << " ";
    }
    cout << endl;
  }
  cout << dp[0] << endl;
  return 0;
}