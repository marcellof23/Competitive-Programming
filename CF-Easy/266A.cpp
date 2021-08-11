#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  int i = 1;
  vector<char> v;
  char curr = s[0];
  v.push_back(curr);
  while (s.size() > 1 && i < s.size())
  {
    if (s[i] == curr)
    {
      i++;
      continue;
    }
    v.push_back(s[i]);
    curr = s[i];
  }
  cout << s.size() - v.size() << endl;
}
