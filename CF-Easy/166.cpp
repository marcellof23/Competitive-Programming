#include <bits/stdc++.h>
using namespace std;

bool compareInterval(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.first > p2.first)
  {
    return true;
  }
  else if (p1.first == p2.first)
  {
    return p1.second < p2.second;
  }
  return false;
}

int main()
{
  int n, k;
  vector<pair<int, int>> v;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), compareInterval);
  int cnt = 0;
  for (auto a : v)
  {
    if (a.first == v[k - 1].first && a.second == v[k - 1].second)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}

/*
2 2
3 1
2 2
4 5
2 2
4 5

2 2 
2 2 
2 2
*/