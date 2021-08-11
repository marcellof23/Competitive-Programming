#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;
  string que, ans;
  cin >> que;

  ans = que;
  for (int a = 0; a < t; a++)
  {
    int i = 0;
    while (i < n)
    {
      if (que[i] == 'G')
      {
        if (i - 1 >= 0 && que[i - 1] == 'B')
        {
          swap(ans[i - 1], ans[i]);
        }
      }
      i++;
    }
    que = ans;
  }
  que = ans;
  cout << que << endl;
}