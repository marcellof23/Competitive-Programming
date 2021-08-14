#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, M;
    cin >> N >> M;
    int tot = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        int x;
        cin >> x;
        tot += x;
      }
    }
    cout << tot << endl;
  }
}