#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
vector<int> vis;
vector<int> parents;
int cs, ce;

bool dfs(int v, int par)
{
  vis[v] = 1;
  for (int u : adj[v])
  {
    if (vis[u] == 2)
    {
      continue;
    }
    if (vis[u] == 1)
    {
      ce = v;
      cs = u;
      return true;
    }
    parents[u] = v;
    if (dfs(u, parents[u]))
    {
      vis[v] = 2;
      return true;
    }
  }
  vis[v] = 2;
  return false;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
  }

  vis.assign(n, 0);
  parents.assign(n, -1);
  cs = -1;
  for (int i = 0; i < n; i++)
  {
    if (!vis[i] && dfs(i, parents[i]))
    {
      break;
    }
  }

  if (cs == -1)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else
  {
    vector<int> ans;
    ans.push_back(cs);
    int cnt = 0;
    for (int v = ce; v != cs; v = parents[v])
    {
      ans.push_back(v);
    }
    ans.push_back(cs);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int a : ans)
    {
      cout << a + 1 << " ";
    }
    cout << endl;
  }
}