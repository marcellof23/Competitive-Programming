#include <bits/stdc++.h>
using namespace std;

int dp[1001][1 << 11];
int solve(int col, int mask, const int m, const int n)
{
  // BASE CASE
  if (col == m + 1)
  {
    if (mask == 0)
      return 1;
    return 0;
  }

  if (dp[col][mask] != -1)
    return dp[col][mask];

  int answer = 0;
  vector<int> next_masks;
  generate_next_masks(mask, 1, 0, n, next_masks);

  for (int next_mask : next_masks)
  {
    answer = (answer + solve(col + 1, next_mask, m, n)) % mod;
  }

  return dp[col][mask] = answer;
}

int main()
{
  init_code();
  int t = 1; //cin >> t;
  while (t--)
  {
    read(n);
    read(m);
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0, m, n);
  }
  return 0;
}
