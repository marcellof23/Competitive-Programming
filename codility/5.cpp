#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int Tcount = 0;
  bool vis[20];
  memset(vis, true, sizeof(vis));
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'H')
    {
      vis[i] = false;
    }
  }

  if (vis[0] == false && vis[1] == false)
  {
    cout << -1 << endl;
    return 0;
  }

  if (vis[n - 2] == false && vis[n - 1] == false)
  {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < n - 2; i++)
  {
    if (vis[i] == false && vis[i + 1] == false && vis[i + 2] == false)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (vis[i] == false)
    {
      if (i + 2 < n && vis[i + 1] == true)
      {
        Tcount++;
        vis[i] = true;
        vis[i + 2] = true;
      }
      else if (i + 3 < n && vis[i + 1] == false)
      {
        Tcount += 2;
        vis[i] = true;
        vis[i + 3] = true;
      }
    }
  }

  if (vis[n - 1] == false)
  {
    Tcount++;
  }
  cout << Tcount << endl;
}