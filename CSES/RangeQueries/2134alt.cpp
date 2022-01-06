#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int NMAX = 2e5 + 6;
int n, m;

vector<int> adj[NMAX];
int nxt[NMAX], sub_size[NMAX], p[NMAX], chain[NMAX], num[NMAX], csz[NMAX], top[NMAX], all, cnt = 1, depth[NMAX];
int arr[NMAX];
ll st[4 * NMAX], mx[4 * NMAX];

ll get_max(int v, int tl, int tr, int l, int r)
{
  if (l > tr || r < tl)
  {
    return 0;
  }
  if (l == tl && r == tr)
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

void dfs(int v, int par)
{
  p[v] = par;
  sub_size[v] = 1;
  for (int i = 0; i < adj[v].size(); i++)
  {
    int to = adj[v][i];
    if (to == par)
    {
      continue;
    }
    depth[to] = depth[v] + 1;
    dfs(to, v);
    sub_size[v] += sub_size[to];
    if (nxt[v] == -1 || sub_size[to] > sub_size[nxt[v]])
    {
      nxt[v] = to;
    }
  }
}

void hld(int v, int par)
{
  chain[v] = cnt - 1;
  num[v] = all++;
  if (!csz[cnt - 1])
  {
    top[cnt - 1] = v;
  }
  ++csz[cnt - 1];
  if (nxt[v] != -1)
  {
    hld(nxt[v], v);
  }
  for (int i = 0; i < adj[v].size(); i++)
  {
    int to = adj[v][i];
    if (to == par || to == nxt[v])
    {
      continue;
    }
    ++cnt;
    hld(to, v);
  }
}

ll go(int a, int b)
{
  ll res = 0;
  while (chain[a] != chain[b])
  {
    if (depth[top[chain[a]]] < depth[top[chain[b]]])
      swap(a, b);
    int start = top[chain[a]];
    if (num[a] == num[start] + csz[chain[a]] - 1)
      res = max(res, mx[chain[a]]);
    else
      res = max(res, get_max(1, 0, n - 1, num[start], num[a]));
    a = p[start];
  }
  if (depth[a] > depth[b])
    swap(a, b);
  res = max(res, get_max(1, 0, n - 1, num[a], num[b]));
  return res;
}

void modif(int a, int b)
{
  update(1, 0, n - 1, num[a], b);
  int s = num[top[chain[a]]];
  int e = s + csz[chain[a]] - 1;
  mx[chain[a]] = get_max(1, 0, n - 1, s, e);
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

  memset(nxt, -1, sizeof(nxt));
  dfs(0, 0);
  hld(0, -1);
  for (int i = 0; i < m; i++)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int x;
    }
    else
    {
    }
  }
}