#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  int grid[n + 1][n + 1], pref[n + 1][n + 1];
  memset(grid, 0, sizeof(grid));
  memset(pref, 0, sizeof(pref));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      char c;
      cin >> c;
      if (c == '*')
        grid[i][j] = 1;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      pref[i][j] = pref[i][j - 1] + grid[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      pref[j][i] = pref[j - 1][i] + pref[j][i];
    }
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //   {
  //     cout << pref[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < q; i++)
  {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1] << endl;
    // cout << pref[x2][y2] << "a" << pref[x2][y1 - 1] << "b" << pref[x1 - 1][y2] << "c" << pref[x1 - 1][y1 - 1] << endl;
  }
}