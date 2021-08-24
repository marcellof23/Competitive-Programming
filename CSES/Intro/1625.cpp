#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ans;
const int MAXN = 7;
char c[MAXN * MAXN + 1];
bool vis[MAXN][MAXN];

bool isValid(int x, int y)
{
  return 0 <= x && x < MAXN && 0 <= y && y < MAXN;
}

void dfs(int x, int y, int i)
{
  if (i == MAXN * MAXN - 1 || (x == MAXN - 1 && y == 0))
  {

    if (i == MAXN * MAXN - 1 && (x == MAXN - 1 && y == 0))
    {
      //memset(vis, 0, sizeof(vis));
      ans += 1;
    }
    return;
  }

  if ((!isValid(x + 1, y) || vis[x + 1][y]) && (!isValid(x - 1, y) || vis[x - 1][y]))
    if (isValid(x, y - 1) && !vis[x][y - 1] && isValid(x, y + 1) && !vis[x][y + 1])
      return;
  if ((!isValid(x, y + 1) || vis[x][y + 1]) && (!isValid(x, y - 1) || vis[x][y - 1]))
    if (isValid(x + 1, y) && !vis[x + 1][y] && isValid(x - 1, y) && !vis[x - 1][y])
      return;

  vis[x][y] = true;

  if (c[i] == 'D' || c[i] == '?')
  {
    if (isValid(x + 1, y) && !vis[x + 1][y])
      dfs(x + 1, y, i + 1);
  }
  if (c[i] == 'U' || c[i] == '?')
  {
    if (isValid(x - 1, y) && !vis[x - 1][y])
      dfs(x - 1, y, i + 1);
  }
  if (c[i] == 'R' || c[i] == '?')
  {
    if (isValid(x, y + 1) && !vis[x][y + 1])
      dfs(x, y + 1, i + 1);
  }
  if (c[i] == 'L' || c[i] == '?')
  {
    if (isValid(x, y - 1) && !vis[x][y - 1])
      dfs(x, y - 1, i + 1);
  }

  vis[x][y] = false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf(" %s", c);
  dfs(0, 0, 0);
  cout << ans << endl;
}