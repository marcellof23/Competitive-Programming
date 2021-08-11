#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int lower = 0, upper = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    s[i] - 'A' <= 26 ? upper++ : lower++;
  }
  if (upper > lower)
  {
    for (int x = 0; x < s.size(); x++)
      putchar(toupper(s[x]));
  }
  else
  {
    for (int x = 0; x < s.size(); x++)
      putchar(tolower(s[x]));
  }
  cout << endl;
}
