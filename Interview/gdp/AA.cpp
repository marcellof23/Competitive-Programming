#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
  if (x.second != y.second)
    return x.second < y.second;
  else
    return x.first < y.first;
}

const int MAXN = 1e5 + 5;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++)
  {
    int left, right;
    cin >> left >> right;
    v.push_back({left, right});
  }

  sort(v.begin(), v.end(), cmp);
  vector<pair<int, int>> ans;
  ans.push_back(v[0]);
  int idx = 0;
  for (int i = 1; i < v.size(); i++)
  {
    if (v[i].first > ans[idx].second)
    {
      ans.push_back({v[i].first, v[i].second});
      idx++;
    }
    else
    {
      ans[idx].first = min(v[i].first, ans[idx].first);
      ans[idx].second = max(v[i].second, ans[idx].second);
    }
  }

  for (int a = 0; a < ans.size(); a++)
  {
    cout << ans[a].first << " " << ans[a].second;
    if (a != ans.size() - 1)
    {
      cout << endl;
    }
  }
}