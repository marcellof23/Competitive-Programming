#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n, q, l;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> adj[maxn];

int dfs(int u, int par)
{
  tin[u] = ++timer;
  up[u][0] = par;
  for (int i = 1; i <= l; i++)
  {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }

  for (auto v : adj[u])
  {
    if (v != par)
      dfs(v, u);
  }

  tout[u] = ++timer;
}

int lca(int u, int v)
{
  if (tin[u] <= tin[v] && tout[u] >= tout[v])
  {
    return u;
  }
  if (tin[v] <= tin[u] && tout[v] >= tout[u])
  {
    return v;
  }
  for (int i = l; i >= 0; i--)
  {
    if (!(tin[up[u][i]] <= tin[v] && tout[up[u][i]] >= tout[v]))
      u = up[u][i];
  }
  return up[u][0];
}

int main()
{
  cin >> n >> q;

  tin.resize(n + 1);
  tout.resize(n + 1);
  timer = 0;
  l = ceil(log2(n + 1));
  up.assign(n + 1, vector<int>(l + 1));

  for (int i = 2; i <= n; i++)
  {
    int x;
    cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  dfs(1, 1);

  while (q--)
  {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << endl;
  }
}
