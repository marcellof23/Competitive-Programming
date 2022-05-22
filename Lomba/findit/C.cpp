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
    ll arr[1005];
    string S, T;

    getline(cin, S);

    stringstream X(S);

    int cnt = 0;
    while (getline(X, T, ' '))
    {
      arr[cnt] = stoll(T);
      cnt++;
    }

    ll tot = 0;
    for (int i = 0; i < cnt; i++)
    {
      if (arr[i] == INT_MIN)
      {
        continue;
      }

      tot++;
      ll curr = arr[i];
      for (int j = i + 1; j < cnt; j++)
      {
        if (curr == arr[j] + 1)
        {
          curr = arr[j];
          arr[j] = INT_MIN;
        }
      }

      arr[i] = INT_MIN;
    }

    cout << tot << endl;
  }
}