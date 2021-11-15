#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp[2];

void dfs(int x, int p)
{
  for (auto v : adj[x])
  {
    if (v == p)
    {
      continue;
    }
    else
    {
      dfs(v, x);
      dp[1][x] += max(dp[1][v], dp[0][v]);
    }
  }
  for (auto v : adj[x])
  {
    if (v == p)
    {
      continue;
    }
    else
    {
      dp[0][x] = max(dp[0][x], 1 + dp[1][x] + dp[1][v] - max(dp[1][v], dp[0][v]));
    }
  }
}

int main()
{
  int n;
  cin >> n;
  adj.resize(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dp[0].resize(n);
  dp[1].resize(n);

  dfs(0, 0);
  for (auto x : dp[0])
  {
    cout << x << " ";
  }
  cout << endl;
  for (auto x : dp[1])
  {
    cout << x << " ";
  }

  cout << max(dp[0][0], dp[1][0]) << endl;
}