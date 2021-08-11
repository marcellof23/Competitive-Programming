#include <bits/stdc++.h>
using namespace std;

int main()
{
  int mat[5][5];
  pair<int, int> loc = {-1, -1};
  memset(mat, 0, sizeof(mat));
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> mat[i][j];
      if (mat[i][j])
      {
        loc.first = i;
        loc.second = j;
      }
    }
  }
  cout << abs(2 - loc.first) + abs(2 - loc.second) << endl;
}