#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;
struct query
{
  int a;
  int b;
  int diff;
} queries[MAXN];

bool cmp(query a, query b)
{
  if (a.b != b.b)
    return a.b < b.b;
  if (a.diff != b.diff)
    return a.diff < b.diff;
  return a.a < b.a;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    queries[i].a = a;
    queries[i].b = b;
    queries[i].diff = b - a;
  }
  sort(queries, queries + n, cmp);

  int cnt = 1;
  pair<int, int> p = {queries[0].a, queries[0].b};
  for (int i = 1; i < n; i++)
  {
    if (p.second <= queries[i].a)
    {
      p = {queries[i].a, queries[i].b};
      cnt++;
    }
  }
  cout << cnt << endl;
}