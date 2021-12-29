#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 3;
  int cnt = 0;
  int limit = 1 << n;
  for (int mask = 1; mask < limit; mask++)
  {
    for (int i = 0; i < n; i++)
    {
      if (((1 << i) & mask) == 0)
        continue;
      cnt++;
      cout << ((1 << i) ^ mask) << endl;
    }
    cout << endl;
  }

  pair<int, int> a = {2, 2};
  pair<int, int> b = {2, 1};

  pair<int, int> c = min(a, b);
  cout << c.second << endl;
  cout << cnt << endl;
}