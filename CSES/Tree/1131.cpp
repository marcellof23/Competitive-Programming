#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int lvl[maxn];
bool vis[maxn];
void dfs(int u, int l)
{
  lvl[u] = l;
  vis[u] = true;
  for (auto v : adj[u])
  {
    if (!vis[v])
      dfs(v, l + 1);
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  memset(lvl, 0, sizeof(lvl));
  memset(vis, false, sizeof(vis));
  dfs(0, 0);

  int maks1 = INT_MIN, maks2 = INT_MIN;
  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    if (maks1 < lvl[i])
    {
      maks1 = lvl[i];
      idx = i;
    }
  }

  int total = 0;

  memset(lvl, 0, sizeof(lvl));
  memset(vis, false, sizeof(vis));

  dfs(idx, 0);

  for (int i = 0; i < n; i++)
  {
    if (maks2 < lvl[i])
    {
      maks2 = lvl[i];
    }
  }
  cout << maks2 << endl;
}
