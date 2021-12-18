#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000069
#define INF 0xf3f3f3f3f3LL

bool vis[MAXN];
ll dp[MAXN];

vector<ll> adj[MAXN], adj_rev[MAXN], S[MAXN];
vector<ll> topo, nodes, components;
ll scc[MAXN], val[MAXN], cnt = 0;
ll f[MAXN];

void dfs1(int s)
{
  vis[s] = true;
  for (auto v : adj[s])
  {
    if (vis[v])
    {
      continue;
    }
    dfs1(v);
  }
  nodes.push_back(s);
}

void dfs2(int s)
{
  scc[s] = cnt;
  val[cnt] += f[s];
  vis[s] = true;
  for (auto v : adj_rev[s])
  {
    if (vis[v])
    {
      continue;
    }
    dfs2(v);
  }
}

void toposort(int s)
{
  vis[s] = true;
  for (auto v : S[s])
  {
    if (vis[v])
    {
      continue;
    }
    toposort(v);
  }
  topo.push_back(s);
}

int main()
{
  int n, m;
  int s, e;
  cin >> n >> m;
  cin >> s >> e;
  for (int i = 1; i <= n; i++)
  {
    cin >> f[i];
  }
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      dfs1(i);
    }
  }

  reverse(nodes.begin(), nodes.end());
  memset(vis, 0, sizeof(vis));

  for (int i : nodes)
  {
    if (!vis[i])
    {
      cnt++;
      dfs2(i);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (auto v : adj[i])
    {
      if (scc[i] != scc[v])
      {
        S[scc[i]].push_back(scc[v]);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << scc[i] << endl;
  }
  memset(vis, 0, sizeof(vis));

  for (int i = 1; i <= cnt; i++)
  {
    if (!vis[i])
    {
      toposort(i);
    }
  }

  for (int i = 0; i < topo.size(); i++)
  {
    dp[topo[i]] = (ll)INF;
  }

  dp[scc[s]] = -val[scc[s]];
  for (int i = (int)topo.size() - 1; i >= 0; i--)
  {
    int u = topo[i];
    for (int j = 0; j < (int)S[u].size(); j++)
    {
      int v = S[u][j];
      dp[v] = min(dp[v], dp[u] - val[v]);
    }
  }

  cout << -dp[scc[e]] << endl;
  return 0;
}
