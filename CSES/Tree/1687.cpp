#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int up[maxn][20];
vector<int> adj[maxn];

void dfs(int v, int p)
{
  up[v][0] = p;
  for (int i = 1; i < 20; i++)
  {
    if (up[v][i - 1] != -1)
      up[v][i] = up[up[v][i - 1]][i - 1];
    else
      up[v][i] = -1;
  }

  for (int u : adj[v])
  {
    if (u != p)
    {
      dfs(u, v);
    }
  }
}

int solve(int node, int k)
{
  if (node == -1 || k == 0)
    return node;
  for (int i = 19; i >= 0; i--)
  {
    if (k >= (1 << i))
    {
      return solve(up[node][i], k - (1 << i));
    }
  }
}

int main()
{

  int n, q;
  cin >> n >> q;

  for (int i = 2; i <= n; i++)
  {
    int x;
    cin >> x;
    adj[x].push_back(i);
    adj[i].push_back(x);
  }
  dfs(1, -1);
  while (q--)
  {
    int node, k;
    cin >> node >> k;
    cout << solve(node, k) << endl;
  }
  return 0;
}