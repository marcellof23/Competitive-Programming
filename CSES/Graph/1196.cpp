#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k;
const ll INF = 1e18 + 7;
vector<pair<int, int>> adj[100005];
vector<vector<ll>> dist;

void dijkstra(int s)
{
  using pii = pair<ll, ll>;
  priority_queue<pii, vector<pii>, greater<pii>> q;

  q.push({0, s});
  while (!q.empty())
  {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();

    if (dist[v][k - 1] < d_v)
      continue;

    for (auto edge : adj[v])
    {
      ll to = edge.first;
      ll len = edge.second;

      if (d_v + len < dist[to][k - 1])
      {
        dist[to][k - 1] = d_v + len;
        q.push({dist[to][k - 1], to});
        sort(dist[to].begin(), dist[to].end());
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m >> k;

  dist.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    dist[i].resize(k);
    for (int j = 0; j < k; ++j)
    {
      dist[i][j] = INF;
    }
  }

  dist[1][0] = 0;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  dijkstra(1);

  for (int i = 0; i < k; i++)
  {
    cout << dist[n][i] << " ";
  }
  cout << endl;
}