

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combine(vector<vector<int>> &it)
{
  sort(it.begin(), it.end());
  int n = it.size();
  vector<vector<int>> ans;
  int prev = 0;
  ans.push_back(it[0]);
  for (int i = 1; i < n; i++)
  {
    if (it[i][0] <= ans[prev][1])
    {
      if (it[i][1] <= ans[prev][1])
      {
        continue;
      }
      ans[prev][1] = it[i][1];
    }
    else
    {
      ans.push_back(it[i]);
      prev++;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> v(n), ans(n);
  for (int i = 0; i < n; i++)
  {
    v[i].resize(2);
    ans[i].resize(2);
  }
  for (int i = 0; i < n; i++)
  {
    int left, right;
    cin >> left >> right;
    v[i][0] = left;
    v[i][1] = right;
  }

  ans = combine(v);
  for (auto a : ans)
  {
    cout << a[0] << " " << a[1] << endl;
  }
}