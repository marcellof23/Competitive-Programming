

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
  if (x.first != y.first)
    return x.first < y.first;
  else
    return x.second < y.second;
}

int main()
{
  int N;
  cin >> N;
  int a[N], b[N];
  pair<int, int> p[N];
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> b[i];
  }
  for (int i = 0; i < N; i++)
  {
    p[i] = {a[i], b[i]};
  }
  sort(p, p + N);

  int curr = p[0].first;
  int curr_maks = p[0].first;
  int maks = p[0].second;
  for (int i = 1; i < N; i++)
  {
    if (p[i].first == curr)
    {
      continue;
    }
    else
    {
      curr = p[i].first;
      if (p[i].second > maks)
      {
        curr_maks = p[i].first;
        maks = p[i].second;
      }
    }
  }
  cout << curr_maks << " " << maks << endl;
}