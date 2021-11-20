#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MAXN = 1e4 + 69;
int tot_nod;
vector<vector<int>> adj;

vector<bool> vis;
vector<int> tin, low;
int times, cnt_cut = 0;

void dfs(int v, int p)
{
  vis[v] = true;
  tin[v] = low[v] = times++;
  int child = 0;
  bool ada = false;
  for (int to : adj[v])
  {
    if (to == p)
    {
      continue;
    }
    if (vis[to])
    {
      low[v] = min(low[v], tin[to]);
    }
    else
    {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] >= tin[v] && p != -1)
      {
        ada = true;
      }
      ++child;
    }
  }
  if (ada)
  {
    cnt_cut++;
  }
  if (p == -1 && child > 1)
  {
    cnt_cut++;
  }
}

void find_cutpoints()
{
  times = 0;
  vis.assign(tot_nod, false);
  tin.assign(tot_nod, -1);
  low.assign(tot_nod, -1);
  dfs(0, -1);
}

int main()
{
  int n = -1, m = -1;

  while (true)
  {
    cnt_cut = 0;
    cin >> n >> m;
    if (n == 0 && m == 0)
    {
      break;
    }
    adj.clear();
    adj.resize(n);

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }
    tot_nod = n;
    find_cutpoints();
    cout << cnt_cut << endl;
  }
}