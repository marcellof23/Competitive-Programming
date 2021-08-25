#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n, x;
  cin >> n >> x;
  int arr[n];
  int minus = 0, total = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = 0;
  int l = 0;
  for (int r = n - 1; r >= l; r--)
  {
    if (arr[l] + arr[r] <= x)
    {
      l++;
    }
    ans++;
  }
  cout << ans << endl;
}