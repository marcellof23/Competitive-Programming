#include <bits/stdc++.h>
using namespace std;
int stockPairs(int stocksProfit[], int target, int n)
{
  sort(stocksProfit, stocksProfit + n);
  // sort the stocksProfit array.
  int low = 0, high = n - 1; // low and high represent two pointers
  int pairs = 0;
  // count of all distinct pairs
  while (low < high)
  {
    // continue while low < high
    if (stocksProfit[low] + stocksProfit[high] == target)
    {
      // find equal then increment pairs
      pairs += 1;
      low += 1;
      high -= 1;
    }
    else if (stocksProfit[low] + stocksProfit[high] < target)
    {
      low += 1;
      // if sum is less than target, then increment low so that sum increases.
    }
    else
    {
      high -= 1;
      // if sum is greater than target, then decrement high so that sum decreases.
    }
  }
  return pairs;
  // return distinct pairs.
}
int main()
{
  int target = 12; // the target
  int stocksProfit[] = {5, 7, 9, 13, 11, 6, 6, 3, 3};
  // the stockProfits array
  int n = sizeof(stocksProfit) / sizeof(stocksProfit[0]);
  // n - represents size of array
  cout << stockPairs(stocksProfit, target, n) << endl;
  // find distinct pairs
}

// // set multiset for effcient find
// multiset<int> ms;

// // create variable n for reuse
// int n = (int)stocksProfit.size();
// for (int i = 0; i < n; i++)
// {
//   ms.insert(stocksProfit[i]);
// }

// vector<pair<int, int>> ans;
// for (auto it = ms.begin(); it != ms.end(); it++)
// {
//   auto position = ms.find(target - *it);
//   auto position_it = ms.find(*it);
//   // if position is found, then there is a pair of ans
//   if (position != ms.end() && (distance(position, position_it) != 0))
//   {
//     ans.push_back({*it, target - *it});
//   }
// }
// int total_duplicate = 0;
// int ans_size = ans.size();

// // swap first and second property of pair
// // so it is sorted by first property, then second property
// for (auto &v : ans)
// {
//   if (v.first > v.second)
//   {
//     swap(v.first, v.second);
//   }
// }

// // sort ans to check duplicate ans in sequence
// sort(ans.begin(), ans.end());

// for (int i = 1; i < ans_size; i++)
// {
//   if ((ans[i].first == ans[i - 1].first) && (ans[i].second == ans[i - 1].second))
//   {
//     total_duplicate++;
//   }
// }
// return ans_size - total_duplicate;