#include <bits/stdc++.h>
using namespace std;
#define ll long long

char alp[3] = {'A', 'B', 'C'};
string alps[7] = {"A", "B", "C", "AB", "AC", "BC", "ABC"};

int main()
{
  int n;
  cin >> n;

  map<string, int> m;

  for (int i = 0; i < 7; i++)
  {
    m.insert({alps[i], 1e9 + 7});
  }

  for (int i = 0; i < n; i++)
  {
    int c;
    string s;
    cin >> c >> s;
    int a[3];
    memset(a, 0, sizeof(a));
    string res;
    for (int i = 0; i < s.length(); i++)
    {
      a[s[i] - 'A'] = 1;
    }
    for (int i = 0; i < 3; i++)
    {
      if (a[i])
      {
        res.push_back(alp[i]);
      }
    }
    auto it = m.find(res);
    m[res] = min(c, it->second);
  }

  int mins = INT_MAX;

  for (auto x : m)
  {
    cout << x.first << " " << x.second << endl;
  }
  char c = 'C' - 0;
  cout << (1 << 0);
}