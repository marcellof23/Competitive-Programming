#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int n;
  cin >> n;
  int arr[n], total = 0;
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    total += arr[i];
  }
  int ways = 0;
  for (int i = 1; i <= 5; i++)
  {
    if ((total + i) % (n + 1) == 1)
    {
      continue;
    }
    ways++;
  }
  cout << ways << endl;
}