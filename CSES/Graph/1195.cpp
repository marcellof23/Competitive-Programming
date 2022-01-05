#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
int n, m;

const int MAXN = 1e5 + 69;
const ll INF = 1e18 + 7;

vector<pii> adj[2][MAXN];
ll dist[2][MAXN];

void dijkstra(int t, int s)
{
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({dist[t][s] = 0, s});
  while (!pq.empty())
  {
    auto pq_top = pq.top();
    int d = pq_top.first;
    int u = pq_top.second;
    pq.pop();
    if (d > dist[t][u])
    {
      continue;
    }
    for (auto a : adj[t][u])
    {
      int v = a.first;
      int w = a.second;
      if (dist[t][v] > dist[t][u] + w)
      {
        dist[t][v] = dist[t][u] + w;
        pq.push({dist[t][v], v});
      }
    }
  }
}

int main()
{
  memset(dist, INF, sizeof(dist));
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[0][u].push_back({v, w});
    adj[1][v].push_back({u, w});
  }
}
