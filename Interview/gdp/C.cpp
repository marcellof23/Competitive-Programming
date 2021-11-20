

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int INF = 100000000;
const char SEP = '#';

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char maps[MAXN][MAXN];
int dist[MAXN][MAXN];

bool valid(int y, int x, int height, int width)
{
  if (x >= 0 && y >= 0 && y < height && x < width && maps[y][x] != SEP && dist[y][x] == INF)
    return true;
  return false;
}

void bfs(int sty, int stx, int height, int width)
{
  int tx, ty, nx, ny;
  queue<int> qx;
  queue<int> qy;

  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      dist[i][j] = INF;

  dist[sty][stx] = 0;
  qx.push(stx);
  qy.push(sty);

  while (!qx.empty())
  {
    tx = qx.front();
    ty = qy.front();
    qx.pop();
    qy.pop();

    for (int i = 0; i < 4; i++)
    {
      nx = tx + dx[i];
      ny = ty + dy[i];

      if (valid(ny, nx, height, width))
      {
        dist[ny][nx] = dist[ty][tx] + 1;
        qy.push(ny);
        qx.push(nx);
      }
    }
  }
}

int main()
{
  int h, w, O, X;

  cin >> h >> w;
  cin >> O >> X;
  int orang[O];
  for (int i = 0; i < O; i++)
  {
    cin >> orang[i];
  }

  pair<int, int> block[X];

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      maps[i][j] = 'O';
    }
  }

  for (int i = 0; i < X; i++)
  {
    int a, b;
    cin >> a >> b;
    maps[--a][--b] = '#';
  }

  int mins = -1e9;
  for (int i = 0; i < O; i++)
  {
    bfs(0, orang[i], h, w);

    int min_step = -1e9;

    for (int i = 0; i < w; i++)
    {
      int ans = 0;
      for (int j = 0; j < h; j++)
      {
        if (dist[j][i] == INF)
        {
          ans++;
        }
      }
      min_step = max(min_step, ans);
    }
    mins = max(mins, min_step);
  }
  cout << mins << endl;

  return 0;
}