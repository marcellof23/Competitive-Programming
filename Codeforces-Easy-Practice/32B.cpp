#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<int> v;
  int i = 0;
  while (i < s.size())
  {
    if (s[i] == '.')
    {
      v.push_back(0);
      i++;
    }
    else if (s[i] == '-' && s[i + 1] == '.')
    {
      v.push_back(1);
      i += 2;
    }
    else if (s[i] == '-' && s[i + 1] == '-')
    {
      v.push_back(2);
      i += 2;
    }
  }
  for (auto a : v)
  {
    cout << a;
  }
  cout << endl;
}