#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int t;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    vector<ll> v;
    bool vis[1005];
    string S, T;

    getline(cin, S);

    stringstream X(S);

    int cnt = 0;
    while (getline(X, T, ' '))
    {
      v.push_back(stoll(T));
      cnt++;
    }

    ll tot = 0;
    for (int i = 0; i < cnt; i++)
    {
      if (vis[i])
      {
        continue;
      }

      tot++;
      ll curr = v[i];
      for (int j = i + 1; j < cnt; j++)
      {
        if (curr == v[j] + 1)
        {
          curr = v[j];
          vis[j] = true;
        }
      }

      vis[i] = true;
    }

    cout << tot << endl;
  }
}