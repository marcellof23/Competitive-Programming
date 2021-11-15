#include <bits/stdc++.h>
using namespace std;

int n;

int stockPairs(int stockProfit[], int target)
{
  multiset<int> ms;
  for (int i = 0; i < n; i++)
  {
    ms.insert(stockProfit[i]);
  }

  vector<pair<int, int>> ans;

  for (auto it = ms.begin(); it != ms.end(); it++)
  {
    auto position = ms.find(target - *it);
    auto position_it = ms.find(*it);
    // if position is found, then there is a pair of ans

    // cout << distance(target - it - ms.begin()) << endl;
    if (position != ms.end())
    {
      ans.push_back({*it, target - *it});
    }
  }

  int cnt = 0;
  int ans_sz = ans.size();
  for (auto &v : ans)
  {
    if (v.first > v.second)
    {
      int temp;
      temp = v.first;
      v.first = v.second;
      v.second = temp;
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans[0].first << " " << ans[0].second << endl;
  for (int i = 1; i < ans_sz; i++)
  {
    cout << ans[i].first << " " << ans[i].second << endl;
    if ((ans[i].first == ans[i - 1].first && ans[i].second == ans[i - 1].second))
    {
      cnt++;
    }
  }

  return ans_sz - cnt;
}

int main()
{
  int target;
  cin >> n >> target;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << stockPairs(arr, target) << endl;
}