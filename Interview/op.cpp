#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 3000005;
const int INF = 1e9 + 7;
int dp[maxn];

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < maxn; i++)
  {
    dp[i] = INF;
  }

  // +1 -1 x2 x3 :2 :3
  //

  dp[n] = 0;
  for (int i = n; i < maxn / 3; i++)
  {
    if (dp[i] == INF)
    {
      continue;
    }
    if (dp[i - 1] == INF)
    {
      dp[i - 1] = dp[i] + 1;
    }
    if (dp[i + 1] == INF)
    {
      dp[i + 1] = dp[i] + 1;
    }
    if (dp[i * 2] == INF)
    {
      dp[i * 2] = dp[i] + 1;
    }
    if (dp[i * 3] == INF)
    {
      dp[i * 3] = dp[i] + 1;
    }
    if (dp[i / 2] == INF)
    {
      dp[i / 2] = dp[i] + 1;
    }
    if (dp[i / 3] == INF)
    {
      dp[i / 3] = dp[i] + 1;
    }
    dp[i * 3] = min(dp[i * 3], 1 + dp[i]);
    dp[i * 2] = min(dp[i * 2], 1 + dp[i]);
    dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
    dp[i / 3] = min(dp[i / 3], 1 + dp[i]);
    dp[i / 2] = min(dp[i / 2], 1 + dp[i]);
    dp[i - 1] = min(dp[i - 1], 1 + dp[i]);
  }

  for (int i = 1; i <= 15; i++)
  {
    cout << dp[i] << endl;
  }
  cout << dp[m];
}