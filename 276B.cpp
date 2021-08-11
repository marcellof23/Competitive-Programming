#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> &a,
         pair<char, int> &b)
{
  return a.second > b.second;
}

int main()
{
  string s;
  cin >> s;
  int total = s.size();
  int tot = total / 2;
  int cnt = 0;
  map<char, int> m;
  for (int i = 0; i < total; i++)
  {
    auto itr = m.find(s[i]);
    if (itr == m.end())
    {
      m.insert({s[i], 1});
    }
    else
    {
      m[s[i]] = itr->second + 1;
    }
  }
  int cntOdd = 0;
  for (auto ma : m)
  {
    // cout << ma.first << " " << ma.second << endl;
    if (ma.second % 2)
    {
      cntOdd++;
    }
  }
  // cout << cntOdd << endl;
  if (cntOdd <= 1 || cntOdd % 2 == 1)
  {
    cout << "First" << endl;
  }
  else
  {
    cout << "Second" << endl;
  }
}