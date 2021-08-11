#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int n, tot = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    if (str[1] == '+')
    {
      ++tot;
    }
    else
    {
      --tot;
    }
  }
  cout << tot << endl;
}