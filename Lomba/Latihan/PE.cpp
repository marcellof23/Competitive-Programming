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
    int N;
    cin >> N;
    int A[N], B[N];
    for (int j = 0; j < N; j++)
    {
      cin >> A[j];
    }
    for (int j = 0; j < N; j++)
    {
      cin >> B[j];
    }

    ll tot = 0;
    for (int j = 0; j < N; j++)
    {
      tot += max(A[j], B[j]);
    }
    cout << "Case #" << i << ": " << tot << endl;
  }
}