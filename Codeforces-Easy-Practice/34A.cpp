#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int currMin = 1e9 + 7;
  pair<int, int> loc;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    int left = i - 1 < 0 ? n - 1 : i - 1;
    int right = i + 1 > n - 1 ? 0 : i + 1;
    if (currMin > abs(arr[i] - arr[left]))
    {
      currMin = abs(arr[i] - arr[left]);
      loc.first = i;
      loc.second = left;
    }
    if (currMin > abs(arr[i] - arr[right]))
    {
      currMin = abs(arr[i] - arr[right]);
      loc.first = i;
      loc.second = right;
    }
  }
  cout << loc.first + 1 << " " << loc.second + 1 << endl;
}
