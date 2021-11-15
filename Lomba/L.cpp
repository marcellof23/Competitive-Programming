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
    ll tot = 0, arr[N];
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
      tot += arr[i];
    }
    sort(arr, arr + N);
    if (tot % 2)
    {
      for (int j = 0; j < N; j++)
      {
        if (arr[j] % 2)
        {
          tot -= arr[j];
          break;
        }
      }
    }
    cout << "Case #" << i << ": " << tot << endl;
  }
}