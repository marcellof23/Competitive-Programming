#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  string s1, s2;
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < s1.length(); i++)
  {
    if (s1[i] == '1' && s2[i] == '0')
    {
      cout << "1";
    }
    else if (s1[i] == '0' && s2[i] == '1')
    {
      cout << "1";
    }
    else
    {
      cout << "0";
    }
  }
  cout << endl;
  return 0;
}