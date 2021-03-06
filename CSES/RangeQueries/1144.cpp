#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 69;
int arr[MAXN];

struct Query
{
  char t;
  int a, b;
};

int n, q, m, fen[MAXN], p[MAXN];

vector<int> cords;
vector<Query> qq;

void add(int p, int v)
{
  for (int i = p; i <= m; i += i & -i)
  {
    fen[i] += v;
  }
}

int get(int p)
{
  int v = 0;
  for (; p >= 1; p -= p & -p)
  {
    v += fen[p];
  }
  return v;
}

int getpos(int x)
{
  return lower_bound(begin(cords), end(cords), x) - cords.begin() + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    cords.emplace_back(p[i]);
  }

  for (int i = 1; i <= k; i++)
  {
    char t;
    int a, b;
    cin >> t >> a >> b;
    qq.push_back({t, a, b});
    if (t == '?')
    {
      cords.emplace_back(a);
    }
    cords.emplace_back(b);
  }

  sort(cords.begin(), cords.end());
  cords.resize(unique(cords.begin(), cords.end()) - cords.begin());

  int csize = cords.size();

  for (int i = 1; i <= n; i++)
  {
    add(getpos(arr[i]), 1);
  }

  for (auto que : qq)
  {
    auto qt = que.t;
    auto qa = que.a;
    auto qb = que.b;

    if (qt == '!')
    {
      add(getpos(arr[qa]), -1);
      arr[qa] = qb;
      add(getpos(arr[qa]), 1);
    }
    else
    {
      cout << (get(getpos(qb)) - get(getpos(qa) - 1)) << endl;
    }
  }
  return 0;
}