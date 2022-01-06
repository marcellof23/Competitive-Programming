#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NMAX = 2e5 + 6;
const ll INF = 1e18 + 7;
vector<int> parent, depth, heavy, head, pos;
vector<int> adj[NMAX];
int arr[NMAX], st[4 * NMAX];
int n, m;

int cur_pos;

int get_max(int v, int tl, int tr, int l, int r)
{
  if (tl > r || tr < l)
  {
    return 0;
  }
  if (tl <= l && r <= tr)
  {
    return st[v];
  }

  int tm = (tl + tr) / 2;
  return max(get_max(2 * v, tl, tm, l, r), get_max(2 * v + 1, tm + 1, tr, l, r));
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
    int cur_heavy_path_max = get_max(1, 1, n, pos[head[b]], pos[b]);
    res = max(res, cur_heavy_path_max);
    b = parent[head[b]];
  }

  if (depth[a] > depth[b])
    swap(a, b);
  int last_heavy_path_max = get_max(1, 1, n, pos[a] + 1, pos[b]);
  res = max(res, last_heavy_path_max);
  return res;
}

void decompose(int v, int h)
{
  head[v] = h, pos[v] = cur_pos++;
  update(1, 1, n, pos[v], arr[v]);
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
  cur_pos = 1;

  dfs(1);
  memset(st, 0, sizeof(st));
  decompose(1, 1);
}

int main()
{
  cin >> n >> m;

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
      update(1, 1, n, pos[u], v);
    }
    else
    {
      cout << query(u, v) << endl;
    }
  }
}