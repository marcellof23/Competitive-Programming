#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;

bool vis[1005][1005];
int grid[1005][1005];
string biner[20];

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

string decToBinary(int n)
{
  string s;
  for (int i = 3; i >= 0; i--)
  {
    int k = n >> i;
    if (k & 1)
      s.append("1");
    else
      s.append("0");
  }
  return s;
}

int room = 0;

void dfs(int i, int j)
{
  vis[i][j] = true;
  for (int k = 0; k < 4; k++)
  {
    int moveX = i + dirX[k];
    int moveY = j + dirY[k];
    if (moveX >= 0 && moveX < n && moveY >= 0 && moveY < m)
    {
      if (biner[grid[moveX][moveY]][(k + 2) % 4] == '1' || biner[grid[i][j]][k] == '1')
      {
        continue;
      }
      if (!vis[moveX][moveY])
      {
        dfs(moveX, moveY);
        room++;
      }
    }
  }
}

void floodfill()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!vis[i][j])
      {
        room = 0;
        dfs(i, j);
        ans.push_back(room + 1);
      }
    }
  }
}

int main()
{

  cin >> n >> m;

  memset(vis, false, sizeof(vis));

  for (int i = 0; i < 16; i++)
  {
    biner[i] = decToBinary(i);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     for (int k = 0; k < 4; k++)
  //     {
  //       int moveX = i + dirX[k];
  //       int moveY = j + dirY[k];
  //       if (moveX >= 0 && moveX < n && moveY >= 0 && moveY < m)
  //       {
  //         if (biner[grid[i][j]][k] == '1')
  //         {
  //           vis[moveX][moveY] = true;
  //         }
  //       }
  //     }
  //   }
  // }

  floodfill();

  sort(ans.begin(), ans.end(), greater<int>());

  for (auto a : ans)
  {
    cout << a << " ";
  }
  cout << endl;
}