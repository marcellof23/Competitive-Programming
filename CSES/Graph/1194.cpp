#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<pair<int, int>>> path;
// vis 0 before filled, vis 1 for monsters vis 2 for player
vector<vector<int>> vis;
pair<int, int> sp;
vector<pair<int, int>> mp, ep;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isInBound(int x, int y)
{
  if (x < 0 || x >= N || y < 0 || y >= M)
  {
    return false;
  }
  if (vis[x][y])
  {
    return false;
  }
  return true;
}

void bfsPlayer()
{
  queue<pair<int, int>> q;
  q.push({sp});
  while (!q.empty())
  {
    int currX = q.front().first;
    int currY = q.front().second;
    q.pop();
    for (auto m : dir)
    {
      if (isInBound(currX + m.first, currY + m.second))
      {
        q.push({currX + m.first, currY + m.second});
        vis[currX + m.first][currY + m.second] = true;
        path[currX + m.first][currY + m.second] = {m.first, m.second};
      }
    }
  }
}

void bfsMonsters()
{
  queue<pair<pair<int, int>, int>> q;
  for (auto m : mp)
  {
    q.push({m, 0});
  }
  while (!q.empty())
  {
    int currX = q.front().first.first;
    int currY = q.front().first.second;
    int times = q.front().second;
    times++;
    q.pop();
    for (auto m : dir)
    {
      if (isInBound(currX + m.first, currY + m.second))
      {
        q.push({{currX + m.first, currY + m.second}, times});
        grid[currX + m.first][currY + m.second] = times;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> N >> M;

  grid.resize(N);
  for (int i = 0; i < N; i++)
  {
    grid[i].resize(M);
  }

  for (int i = 0; i < N; i++)

  {
    for (int j = 0; j < M; j++)
    {
      grid[i][j] = INT_MAX;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      char c;
      cin >> c;
      if (c == '#')
      {
        grid[i][j] = 0;
      }
      else if (c == 'A')
      {
        grid[i][j] = 0;
        sp = {i, j};
      }
      else if (c == 'M')
      {
        grid[i][j] = 0;
        mp.push_back({i, j});
      }
      else
      {
        grid[i][j] = INT_MAX;
      }
    }
  }
  if (sp.first == 0 || sp.second == 0 || sp.first == N - 1 || sp.second == M - 1)
  {
    cout << "YES" << endl;
    cout << 0 << endl;
    return 0;
  }
  bfsMonsters();
  bfsPlayer();
}