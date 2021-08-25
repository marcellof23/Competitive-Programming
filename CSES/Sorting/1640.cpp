#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, x;
  cin >> n >> x;
  multimap<int, int> ms;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    ms.insert({a, i});
  }
  for (auto it = ms.begin(); it != ms.end(); it++)
  {
    auto pos = ms.find(x - it->first);
    if (pos != ms.end())
    {
      if (it->second == pos->second)
      {
        continue;
      }
      cout << it->second + 1 << " " << pos->second + 1 << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
