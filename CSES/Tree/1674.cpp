#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int n, m, x;
vector<int> adj[maxn];
int sz[maxn];

void dfs(int u, int p)
{
  sz[u] = 1;
  for (int v : adj[u])
  {
    if (v != p)
    {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    int x;
    cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++)
  {
    cout << sz[i] - 1 << " ";
  }
}