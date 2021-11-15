#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define DFS_WHITE -1
#define DFS_BLACK 1

vi dfs_num;
vi dfs_low;
vi articulation_vertex;
vi S, visited;
vector<vii> AdjList;
int dfsNumberCounter, dfsRoot, rootChildren, numSCC;

void tarjanSCC(int u)
{
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
  S.push_back(u);                               // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++)
  {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first]) // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u])
  {                              // if this is a root (start) of an SCC
    printf("SCC %d:", ++numSCC); // this part is done after recursion
    while (1)
    {
      int v = S.back();
      S.pop_back();
      visited[v] = 0;
      printf(" %d", v);
      if (u == v)
        break;
    }
    printf("\n");
  }
}

int main()
{
  int V, M;

  cin >> V >> M;
  AdjList.assign(V, vii());

  for (int i = 0; i < M; i++)
  {
    int x, y;
    cin >> x >> y;
    AdjList[--x].push_back({--y, 0});
  }

  dfs_num.assign(V, DFS_WHITE);
  dfs_low.assign(V, 0);
  visited.assign(V, 0);
  dfsNumberCounter = numSCC = 0;
  for (int i = 0; i < V; i++)
    if (dfs_num[i] == DFS_WHITE)
      tarjanSCC(i);
}
