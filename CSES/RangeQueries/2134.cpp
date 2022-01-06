#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast,inline") // O1 - O2 - O3 - Os - Ofast
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NMAX = 2e5 + 10;
vector<int> parent, depth, heavy, head, pos;
vector<int> adj[NMAX];
int arr[NMAX], st[4 * NMAX];
int n, m;

int cur_pos;

int get_max(int v, int tl, int tr, int l, int r)
{
  if (l > r)
  {
    return 0;
  }
  if (tl == l && r == tr)
  {
    return st[v];
  }

  int tm = (tl + tr) / 2;
  return max(get_max(2 * v, tl, tm, l, min(tm, r)), get_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int newval)
{
  if (tl == tr)
  {
    st[v] = newval;
    return;
  }
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, newval);
    else
      update(2 * v + 1, tm + 1, tr, pos, newval);
    st[v] = max(st[2 * v], st[2 * v + 1]);
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
    int cur_heavy_path_max = get_max(1, 0, n - 1, pos[head[b]], pos[b]);
    res = max(res, cur_heavy_path_max);
    b = parent[head[b]];
  }

  if (depth[a] > depth[b])
    swap(a, b);
  int last_heavy_path_max = get_max(1, 0, n - 1, pos[a], pos[b]);
  res = max(res, last_heavy_path_max);
  return res;
}

void decompose(int v, int h)
{
  head[v] = h, pos[v] = cur_pos++;
  update(1, 0, n - 1, pos[v], arr[v]);
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  init();

  while (m--)
  {
    int op, u, v;
    cin >> op >> u >> v;
    --u;
    if (op == 1)
    {
      update(1, 0, n - 1, pos[u], v);
    }
    else
    {
      --v;
      cout << query(u, v) << '\n';
    }
  }
  return 0;
}