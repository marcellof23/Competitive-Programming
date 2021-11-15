#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> v, int K, int n, int m, int t)
{
  int prefsum[n + 1][m + 1];
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (i == 0 || j == 0)
      {
        prefsum[i][j] == 0;
        continue;
      }
      else
      {
        prefsum[i][j] = v[i - 1][j - 1] + prefsum[i - 1][j] + prefsum[i][j - 1] - prefsum[i - 1][j - 1];
      }
    }
  }

  int tot = 0;
  int tot2 = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (i - 1 + tot > n || j - 1 + tot > m)
      {
        break;
      }
      int down = tot;
      int up = ((n - i + 1) > (m - j + 1)) ? (m - j + 1) : (n - i + 1);
      while (down < up)
      {
        int center = (down + up + 1) / 2;

        if (prefsum[i - 1 + center][j - 1 + center] + prefsum[i - 1][j - 1] - prefsum[i - 1 + center][j - 1] - prefsum[i - 1][j - 1 + center] > K)
        {
          up = center - 1;
        }
        else
        {
          down = center;
        }
      }
      //tot = max(down, tot);
      if (down > tot)
      {
        tot = down;
        tot2 = up;
      }
    }
  }
  cout << "Case #" << t << ": " << tot << " " << tot2;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        cin >> v[i][j];
      }
    }
    solve(v, K, N, M, t);
  }
}