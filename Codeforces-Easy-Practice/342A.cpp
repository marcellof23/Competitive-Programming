#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int tot = n, groupa = 0, groupb = 0, groupc = 0;
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    auto itr = m.find(x);
    if (itr == m.end())
    {
      m.insert({x, 1});
    }
    else
    {
      m[x] = itr->second + 1;
    }
  }
  if (m[5] > 0 || m[7] > 0)
  {
    cout << -1 << endl;
    return 0;
  }
  while (1)
  {
    if (m[1] && m[2] && m[4])
    {
      --m[1];
      --m[2];
      --m[4];
      groupa++;
      tot -= 3;
      continue;
    }
    if (m[1] && m[2] && m[6])
    {
      --m[1];
      --m[2];
      --m[6];
      groupb++;
      tot -= 3;
      continue;
    }
    if (m[1] && m[3] && m[6])
    {
      --m[1];
      --m[3];
      --m[6];
      groupc++;
      tot -= 3;
      continue;
    }
    break;
  }
  if (tot == 0)
  {
    while (groupa--)
    {
      cout << 1 << " " << 2 << " " << 4 << endl;
    }
    while (groupb--)
    {
      cout << 1 << " " << 2 << " " << 6 << endl;
    }
    while (groupc--)
    {
      cout << 1 << " " << 3 << " " << 6 << endl;
    }
    return 0;
  }
  cout << -1 << endl;
  return 0;
}