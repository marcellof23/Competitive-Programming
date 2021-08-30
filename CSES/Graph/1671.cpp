#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18 + 7;
vector<pair<int, int>> adj[100005];
vector<ll> d(100005);

void dijkstra(int s, int n)
{
  d.assign(n, INF);

  d[s] = 0;
  using pii = pair<ll, ll>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty())
  {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : adj[v])
    {
      ll to = edge.first;
      ll len = edge.second;

      if (d[v] + len < d[to])
      {
        d[to] = d[v] + len;
        q.push({d[to], to});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, A, B, C;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    adj[u].push_back({v, w});
  }
  dijkstra(0, N);
  for (int i = 0; i < N; i++)
  {
    cout << d[i] << " ";
  }
  cout << endl;
}