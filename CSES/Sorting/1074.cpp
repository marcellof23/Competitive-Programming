#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int mid = arr[n / 2];
  long long tot = 0;
  for (int i = 0; i < n; i++)
  {
    tot += abs(mid - arr[i]);
  }
  cout << tot << endl;
}