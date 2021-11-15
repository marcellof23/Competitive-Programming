#include <bits/stdc++.h>
using namespace std;

int maxBracket(string str)
{
  stack<int> s;
  s.push(-1);
  int len = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(')
    {
      s.push(i);
    }
    else
    {
      s.pop();
      if (s.empty())
      {
      }
    }
  }
}

int main()
{
}