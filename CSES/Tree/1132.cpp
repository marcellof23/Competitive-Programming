#include <bits/stdc++.h>
using namespace std;

const int NMAX = 5e5 + 5;

vector<int> adj[NMAX];
int dist[NMAX], ans[NMAX];

void dfs(int u, int par)
{
  for (auto i : adj[u])
  {
    if (i != par)
    {
      dist[i] = dist[u] + 1;
      dfs(i, u);
    }
  }
}

void dfs_init(int u)
{
  memset(dist, 0, sizeof(dist));
  dfs(u, -1);
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs_init(1);
  int best_dist = 0;
  for (int i = 1; i <= n; i++)
  {
    if (dist[i] > dist[best_dist])
      best_dist = i;
  }
  dfs_init(best_dist);

  for (int i = 1; i <= n; i++)
  {
    ans[i] = dist[i];
  }

  for (int i = 1; i <= n; i++)
  {
    if (dist[i] > dist[best_dist])
      best_dist = i;
  }
  dfs_init(best_dist);
  for (int i = 1; i <= n; i++)
  {
    ans[i] = max(ans[i], dist[i]);
  }
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << " ";
  }
}