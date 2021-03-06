#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NMAX = 2e5 + 6;
const ll INF = 1e18 + 7;
vector<int> parent, depth, heavy, head, pos;
vector<int> adj[NMAX];
int arr[NMAX], st[4 * NMAX];
int n, m, N;

int cur_pos;

ll get_max(int a, int b)
{
  a += N, b += N;
  int s = 0;
  while (a <= b)
  {
    if (a & 1)
    {
      s = max(s, st[a]);
      a++;
    }
    if (~b & 1)
    {
      s = max(s, st[b]);
      b--;
    }
    a >>= 1, b >>= 1;
  }
  return s;
}

void update(int k, int x)
{
  k += N;
  st[k] = x;
  k >>= 1;
  while (k > 0)
  {
    st[k] = max(st[2 * k], st[2 * k + 1]);
    k >>= 1;
  }
}

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

int query(int a, int b)
{
  int res = 0;
  while (head[a] != head[b])
  {
    if (depth[head[a]] > depth[head[b]])
      swap(a, b);
    int cur_heavy_path_max = get_max(pos[head[b]] - 1, pos[b] - 1);
    res = max(res, cur_heavy_path_max);
    b = parent[head[b]];
  }

  if (depth[a] > depth[b])
    swap(a, b);
  int last_heavy_path_max = get_max(pos[a] - 1, pos[b] - 1);
  res = max(res, last_heavy_path_max);
  return res;
}

void decompose(int v, int h)
{
  head[v] = h, pos[v] = cur_pos++;
  update(pos[v] - 1, arr[v]);
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
  parent = vector<int>(NMAX);
  depth = vector<int>(NMAX);
  heavy = vector<int>(NMAX, -1);
  head = vector<int>(NMAX);
  pos = vector<int>(NMAX);
  cur_pos = 0;

  dfs(1);
  decompose(1, 1);
}

int main()
{
  cin >> n >> m;

  N = 1 << (int)ceil(log2(n));

  for (int i = 1; i <= n; i++)
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

  init();

  while (m--)
  {
    int op, u, v;
    cin >> op >> u >> v;
    if (op == 1)
    {
      update(pos[u] - 1, v);
    }
    else
    {
      cout << query(u, v) << endl;
    }
  }
}