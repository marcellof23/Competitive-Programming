#include <bits/stdc++.h>
#define int long long
#define inf 1e7
using namespace std;
// DP 3
int solve()
{
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(8, inf));
  dp[0][0] = 0;

  // all costs
  for (int i = 0; i < n; i++)
  {
    int cost;
    string s;
    cin >> cost >> s;
    int string_mask = 0;
    for (int pos = 0; pos < 3; pos++)
    {
      char c = 'C' - pos;
      bool have = 0;
      for (char d : s)
      {
        if (c == d)
        {
          have = 1;
        }
      }
      if (have == 1)
      {
        string_mask += (1 << pos);
      }
    }
    for (int mask = 0; mask < 8; mask++)
    {
      dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
      dp[i + 1][mask | string_mask] = min(dp[i + 1][mask | string_mask], dp[i][mask] + cost);
    }
  }

  int sol = dp[n][7];
  if (sol == inf)
    sol = -1;
  cout << sol << endl;
  return 0;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
}