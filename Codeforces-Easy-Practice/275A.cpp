#include <bits/stdc++.h>
using namespace std;

int xi[4] = {1, 0, -1, 0};
int yi[4] = {0, 1, 0, -1};
int main()
{
  bool grid[3][3];
  memset(grid, false, sizeof(grid));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int x;
      cin >> x;
      if (x % 2 == 1)
      {
        grid[i][j] = !grid[i][j];
        for (int dir = 0; dir < 4; dir++)
        {
          if (i + xi[dir] >= 0 && i + xi[dir] < 3 && j + yi[dir] >= 0 && j + yi[dir] < 3)
            grid[i + xi[dir]][j + yi[dir]] = !grid[i + xi[dir]][j + yi[dir]];
        }
      }
    }
  }
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << !grid[i][j];
    }
    cout << endl;
  }
}