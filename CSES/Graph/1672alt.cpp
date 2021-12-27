#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1e9 + 7;
vector<vector<pair<int, int>>> adj;
vector<int> d, p;

void dijsktra(int s, int sz)
{
  int n = sz;
  d.assign(n, INF);
  p.assign(n, -1);
  d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, s});
  while (!q.empty())
  {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d[v] != d_v)
    {
      continue;
    }
    for (auto e : adj[v])
    {
      int target = e.first;
      int length = e.second;
      if (d[v] + length < d[target])
      {
        d[target] = d[v] + length;
        q.emplace(d[target], target);
      }
    }
  }
}
int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  for (int i = 0; i < q; i++)
  {
    int a, b;
  }
}