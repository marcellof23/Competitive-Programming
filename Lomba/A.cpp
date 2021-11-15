#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    int tot = INT_MIN;
    int curr = 0;
    bool closed = false;
    string str;
    cin >> str;
    int start = 0;
    for (int i = 0; i < str.size(); i++)
    {
      if (str[i] == '(' && curr < 0)
      {
        curr = 1;
        start = 1;
        continue;
      }
      if (str[i] == '(')
      {
        curr++;
      }
      else
      {
        curr--;
      }
      start++;
      if (curr == 0)
      {
        tot = max(tot, start);
        start = 0;
      }
    }
    if (tot == INT_MIN)
    {
      cout << "Case #" << i << ": " << 0 << endl;
      continue;
    }
    cout << "Case #" << i << ": " << tot << endl;
  }
}