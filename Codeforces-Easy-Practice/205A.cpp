#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int n;
  cin >> n;
  int arr[n];
  int idx = -1;
  int minim = 1e9 + 7;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (minim > arr[i])
    {
      minim = arr[i];
      idx = i + 1;
    }
  }
  sort(arr, arr + n);
  int min = arr[0];
  if (n >= 2 && arr[0] == arr[1])
  {
    cout << "Still Rozdil" << endl;
  }
  else
  {
    cout << idx << endl;
  }
}