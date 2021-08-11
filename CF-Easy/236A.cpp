#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  set<char> s;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++)
  {
    s.insert(str[i]);
  }
  if (s.size() % 2)
  {
    cout << "IGNORE HIM!" << endl;
  }
  else
  {
    cout << "CHAT WITH HER!" << endl;
  }
}