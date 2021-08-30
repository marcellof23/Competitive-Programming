#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;

int N, arr[MAXN], ans[MAXN];

int main()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> arr[i];
    int k = i - 1;
    while (arr[k] >= arr[i])
    {
      k = ans[k];
      cout << k << " ";
    }
    cout << endl;
    ans[i] = k;
    // cout << ans[i] << " ";
  }
  cout << endl;
}