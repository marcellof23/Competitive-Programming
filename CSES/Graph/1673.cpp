#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e16;
const int NMAX = 3e3 + 5;
vector<bool> vis(NMAX, 0);
vector<int> adj[NMAX];

void dfs(int v)
{
  vis[v] = true;
  for (auto &u : adj[v])
  {
    if (!vis[u])
      dfs(u);
  }
  return;
}

signed main()
{
  int n, m;
  cin >> n >> m;

  vector<pair<pair<int, int>, int>> ip(m);
  for (int i = 0; i < m; i++)
  {
    cin >> ip[i].first.first >> ip[i].first.second >> ip[i].second;
    adj[ip[i].first.first].push_back(ip[i].first.second);
  }

  vector<int> dist(n + 1, -INF);
  dist[1] = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (dist[ip[j].first.first] != -INF && dist[ip[j].first.first] + ip[j].second > dist[ip[j].first.second])
      {
        dist[ip[j].first.second] = dist[ip[j].first.first] + ip[j].second;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    if (dist[ip[i].first.first] != -INF && (dist[ip[i].first.first] + ip[i].second > dist[ip[i].first.second]))
    {
      dfs(ip[i].first.first);
    }
  }

  if (!vis[n])
  {
    cout << dist[n] << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}