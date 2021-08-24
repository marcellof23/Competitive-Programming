#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n, k;
  cin >> n >> k;
  string s;
  map<char, int> m;
  cin >> s;
  for (int i = 0; i < k; i++)
  {
    char c;
    cin >> c;
    m.insert({c, 1});
  }

  int itr = 0;
  vector<ll> dp;
  while (itr < n)
  {
    ll cnt = 0;
    while (itr < n)
    {
      auto it = m.find(s[itr]);
      if (it != m.end())
      {
        itr++;
        cnt++;
      }
      else
      {
        break;
      }
    }
    dp.push_back(cnt);
    itr++;
  }
  ll total = 0;
  for (auto ans : dp)
  {
    total += ((ans * (ans + 1)) / 2);
  }
  cout << total << endl;
}