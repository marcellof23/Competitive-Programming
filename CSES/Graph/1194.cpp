#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<pair<int, int>>> path;
// vis 0 before filled, vis 1 for monsters vis 2 for player
vector<vector<int>> vis;
pair<int, int> sp, se;
vector<pair<int, int>> mp, ep;
map<pair<int, int>, pair<int, int>> par_mp;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isInBound(int x, int y, int timer)
{
  if (x < 0 || x >= N || y < 0 || y >= M)
  {
    return false;
  }
  if (grid[x][y] <= timer)
  {
    return false;
  }
  return true;
}

bool isEscape(int x, int y, int timer)
{
  if (!isInBound(x, y, timer))
    return false;
  if (x == 0 or y == 0 or
      x == N - 1 or y == M - 1)
    return true;
  return false;
}
bool bfsPlayer()
{
  queue<pair<pair<int, int>, int>> q;
  q.push({sp, 0});
  par_mp[sp] = {-1, -1};
  while (!q.empty())
  {
    int currX = q.front().first.first;
    int currY = q.front().first.second;
    int times = q.front().second;
    times++;
    q.pop();
    for (auto m : dir)
    {
      if (isEscape(currX + m.first, currY + m.second, times))
      {
        par_mp[{currX + m.first, currY + m.second}] = {currX, currY};
        se = {currX + m.first, currY + m.second};
        return true;
      }
      if (isInBound(currX + m.first, currY + m.second, times))
      {
        par_mp[{currX + m.first, currY + m.second}] = {currX, currY};
        q.push({{currX + m.first, currY + m.second}, times});
        grid[currX + m.first][currY + m.second] = times;
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
      if (isInBound(currX + m.first, currY + m.second, times))
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
  if (!bfsPlayer())
  {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  pair<int, int> tmpEnd = se;
  pair<int, int> tmp_par = par_mp[se];
  pair<int, int> ed = {-1, -1};
  vector<char> ans;
  while (tmp_par != ed)
  {
    if ((tmpEnd.second - tmp_par.second) == 1 and (tmpEnd.first - tmp_par.first) == 0)
    {
      ans.push_back('R');
    }
    if ((tmpEnd.second - tmp_par.second) == -1 and (tmpEnd.first - tmp_par.first) == 0)
    {
      ans.push_back('L');
    }
    if ((tmpEnd.second - tmp_par.second) == 0 and (tmpEnd.first - tmp_par.first) == 1)
    {
      ans.push_back('D');
    }
    if ((tmpEnd.second - tmp_par.second) == 0 and (tmpEnd.first - tmp_par.first) == -1)
    {
      ans.push_back('U');
    }
    tmpEnd = par_mp[tmpEnd];
    tmp_par = par_mp[tmpEnd];
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto c : ans)
  {
    cout << c;
  }
}