#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e5 + 6;

vector<int> parent, depth, heavy, head, pos;
vector<int> adj[NMAX];
int arr[NMAX];

int n, m;

int cur_pos;

int dfs(int v)
{
  int size = 1;
  int max_c_size = 0;
  for (int c : adj[v])
  {
    if (c != parent[v])
    {
      parent[c] = v, depth[c] = depth[v] + 1;
      int c_size = dfs(c);
      size += c_size;
      if (c_size > max_c_size)
        max_c_size = c_size, heavy[v] = c;
    }
  }
  return size;
}

void decompose(int v, int h)
{
  head[v] = h, pos[v] = cur_pos++;
  if (heavy[v] != -1)
    decompose(heavy[v], h);
  for (int c : adj[v])
  {
    if (c != parent[v] && c != heavy[v])
      decompose(c, c);
  }
}

void init()
{
  parent = vector<int>(n);
  depth = vector<int>(n);
  heavy = vector<int>(n, -1);
  head = vector<int>(n);
  pos = vector<int>(n);
  cur_pos = 0;

  dfs(0);
  decompose(0, 0);
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}