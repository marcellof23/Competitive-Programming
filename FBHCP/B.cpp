#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int n, totSet = 0, itr = 0, mindot = INT_MAX;
    cin >> n;
    char grid[n][n];
    bool vis[2 * n];
    memset(vis, false, sizeof(vis));
    multiset<int> ans;
    for (int i = 0; i < n; i++)
    {
      string str;
      cin >> str;
      for (int j = 0; j < str.size(); j++)
      {
        grid[itr][j] = str[j];
      }
      itr++;
    }
    // iterate the row
    for (int i = 0; i < n; i++)
    {
      int jumX = 0, jumO = 0, jumDot = 0;
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 'X')
        {
          jumX++;
        }
        else if (grid[i][j] == 'O')
        {
          jumO++;
        }
        else
        {
          jumDot++;
        }
      }
      if (jumX + jumDot == n)
      {
        mindot = min(mindot, jumDot);
      }
    }

    // iterate the column
    for (int i = 0; i < n; i++)
    {
      int jumX = 0, jumO = 0, jumDot = 0;
      for (int j = 0; j < n; j++)
      {
        if (grid[j][i] == 'X')
        {
          jumX++;
        }
        else if (grid[j][i] == 'O')
        {
          jumO++;
        }
        else
        {
          jumDot++;
        }
      }
      if (jumX + jumDot == n)
      {
        mindot = min(mindot, jumDot);
      }
    }
    for (int i = 0; i < n; i++)
    {
      int jumX = 0, jumO = 0, jumDot = 0;
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 'X')
        {
          jumX++;
        }
        else if (grid[i][j] == 'O')
        {
          jumO++;
        }
        else
        {
          jumDot++;
        }
      }
      if (jumX + jumDot == n && jumDot == mindot)
      {
        totSet++;
      }
    }
    for (int i = 0; i < n; i++)
    {
      int jumX = 0, jumO = 0, jumDot = 0;
      for (int j = 0; j < n; j++)
      {
        if (grid[j][i] == 'X')
        {
          jumX++;
        }
        else if (grid[j][i] == 'O')
        {
          jumO++;
        }
        else
        {
          jumDot++;
        }
      }
      if (jumX + jumDot == n && jumDot == mindot)
      {
        totSet++;
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '.')
        {
          int jumX = 0, jumO = 0, jumDot = 0;
          for (int k = 0; k < n; k++)
          {
            if (grid[i][k] == 'X')
            {
              jumX++;
            }
            else if (grid[i][k] == 'O')
            {
              jumO++;
            }
            else
            {
              jumDot++;
            }
          }
          for (int k = 0; k < n; k++)
          {
            if (grid[k][j] == 'X')
            {
              jumX++;
            }
            else if (grid[k][j] == 'O')
            {
              jumO++;
            }
            else
            {
              jumDot++;
            }
          }
          // cout << i << " " << j << "s";
          if (jumX == (2 * n - 2) && jumDot == 2)
          {
            totSet--;
          }
        }
      }
    }
    if (mindot == INT_MAX)
      cout << "Case #" << t << ": "
           << "Impossible"
           << "\n";
    else
      cout << "Case #" << t << ": " << mindot << " " << totSet << "\n";
  }
}