#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, s, f;
  cin >> n >> m >> s >> f;
  int t[m], l[m], r[m];
  for (int i = 0; i < m; i++)
  {
    cin >> t[i] >> l[i] >> r[i];
  }
  if (s < f)
  {
    int time = 0;
    int curTime = 1;
    while (s < f)
    {
      if (curTime == t[time])
      {
        if (!(s >= l[time] && s <= r[time]) && !((s + 1) >= l[time] && (s + 1) <= r[time]))
        {
          // cout << s << " " << t[time];
          cout << "R";
          s++;
        }
        else
        {
          // cout << s << " " << t[time];
          cout << "X";
        }
      }
      else
      {
        cout << "R";
        s++;
      }

      if (curTime >= t[time] && time != (m - 1))
      {
        time++;
      }
      ++curTime;
    }
  }
  else
  {
    int time = 0;
    int curTime = 1;
    while (s > f)
    {
      if (curTime == t[time])
      {
        if (!(s >= l[time] && s <= r[time]) && !((s - 1) >= l[time] && (s - 1) <= r[time]))
        {
          // cout << s << " " << t[time];
          cout << "L";
          s--;
        }
        else
        {
          // cout << s << " " << t[time];
          cout << "X";
        }
      }
      else
      {
        cout << "L";
        s--;
      }

      if (curTime >= t[time] && time != (m - 1))
      {
        time++;
      }
      ++curTime;
    }
  }
  return 0;
}