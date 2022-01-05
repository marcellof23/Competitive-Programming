#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> x;
    int ans = 0;
    for (int j = 1; j * j <= x; j++)
    {
      if (x % j == 0)
      {
        ++ans;
        if (j * j != x)
        {
          ++ans;
        }
      }
    }
    cout << ans << endl;
  }
}