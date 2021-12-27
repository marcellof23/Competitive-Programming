#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18 + 7;

ll adj[505][505];

int n, m, q;

void floyd()
{
  for (int k = 0; k <= n; k++)
  {
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= n; j++)
      {
        if (adj[i][k] + adj[k][j] < adj[i][j] && adj[k][j] != INF && adj[i][k] != INF)
        {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
}

int main()
{
  cin >> n >> m >> q;

  for (int i = 0; i < 505; i++)
  {
    for (int j = 0; j < 505; j++)
      adj[i][j] = INF;
    adj[i][i] = 0;
  }
  for (int i = 0; i < m; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    adj[u][v] = min(adj[u][v], w);
    adj[v][u] = min(adj[v][u], w);
  }

  floyd();

  while (q--)
  {
    int q1, q2;
    cin >> q1 >> q2;
    if (adj[q1][q2] >= INF)
      cout << -1 << endl;
    else
      cout << adj[q1][q2] << endl;
  }
}