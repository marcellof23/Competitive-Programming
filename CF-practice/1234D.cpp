#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 69;
int n, st[4 * MAXN][26];

string str;

int cnt[26];

void build(int v, int tl, int tr)
{
  if (tl == tr)
  {
    st[v][str[tl] - 'a'] = 1;
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build((2 * v) | 1, tm + 1, tr);
    for (int i = 0; i < 26; i++)
    {
      if (st[2 * v][i] || st[(2 * v) | 1][i])
      {
        st[v][i] = 1;
      }
    }
  }
}

void update(int v, int tl, int tr, int pos, int newv)
{
  if (tl == tr)
  {
    for (int i = 0; i < 26; i++)
    {
      st[v][i] = 0;
    }
    st[v][newv] = 1;
  }
  else
  {
    for (int i = 0; i < 26; i++)
    {
      st[v][i] = 0;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, newv);
    else
      update((2 * v) | 1, tm + 1, tr, pos, newv);
    for (int i = 0; i < 26; i++)
    {
      if (st[2 * v][i] || st[(2 * v) | 1][i])
      {
        st[v][i] = 1;
      }
    }
  }
}

void get(int v, int tl, int tr, int l, int r)
{
  if (l > r)
  {
    return;
  }
  if (l == tl && r == tr)
  {
    int ans = 0;
    for (int j = 0; j < 26; j++)
    {
      if (st[v][j])
      {
        cnt[j] = 1;
      }
    }
    return;
  }
  int tm = (tl + tr) / 2;
  get(2 * v, tl, tm, l, min(r, tm));
  get((2 * v) | 1, tm + 1, tr, max(l, tm + 1), r);
  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> str;
  cin >> n;
  int sz = str.size();
  build(1, 0, sz - 1);
  for (int i = 0; i < n; i++)
  {
    int param, tl, tr;
    char trc;
    cin >> param;
    if (param == 1)
    {
      cin >> tl >> trc;
      --tl;
      update(1, 0, sz - 1, tl, trc - 'a');
    }
    else if (param == 2)
    {
      memset(cnt, 0, sizeof(cnt));
      cin >> tl >> tr;
      int ans = 0;
      --tl;
      --tr;
      get(1, 0, sz - 1, tl, tr);

      for (int j = 0; j < 26; j++)
      {
        if (cnt[j])
        {
          ++ans;
        }
      }
      cout << ans << endl;
    }
  }
}