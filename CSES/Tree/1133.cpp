#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nmax = 2e5 + 5;
vector<int> tree[nmax];
ll subAns[nmax];
ll ans[nmax];
ll subtreeSize[nmax];

void dfs_init(int src, int par)
{
  int nodes_num = 1;
  ll ans_subtree = 0;
  for (auto u : tree[src])
  {
    if (u != par)
    {
      dfs_init(u, src);
      nodes_num += subtreeSize[u];
      ans_subtree += (subtreeSize[u] + subAns[u]);
    }
  }

  subtreeSize[src] = nodes_num;
  subAns[src] = ans_subtree;
}

void dfs(int src, int par, ll par_ans, int totalNodes)
{
  ans[src] = subAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
  for (int u : tree[src])
  {
    if (u != par)
    {
      dfs(u, src, ans[src] - (subAns[u] + subtreeSize[u]), totalNodes);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs_init(1, 0);

  // for (int i = 0; i <= n; i++)
  // {
  //   cout << subAns[i] << " " << subtreeSize[i] << endl;
  // }

  dfs(1, 0, 0, n);
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << ' ';
  }
  return 0;
}