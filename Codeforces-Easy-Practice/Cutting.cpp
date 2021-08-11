#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, B;
  cin >> n >> B;
  int arr[n], inp[n];
  int cnt = 0;
  memset(arr, 0, sizeof(arr));
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> inp[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      if (inp[i] % 2 == 1)
      {
        cnt++;
        arr[0] -= 1;
      }
      else
      {
        arr[0] += 1;
      }
    }
    else
    {
      if (inp[i] % 2)
      {
        cnt++;
        arr[i] += (arr[i - 1] - 1);
      }
      else
      {
        arr[i] += (arr[i - 1] + 1);
      }
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   cout << arr[i] << " ";
  // }
  if (cnt * 2 == n)
  {
    for (int i = 1; i < n - 1; i++)
    {
      if (!arr[i])
      {
        v.push_back(abs(inp[i + 1] - inp[i]));
      }
    }
    sort(v.begin(), v.end());
    // cout << endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //   cout << v[i] << " ";
    // }
    // cout << endl;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
      if (total + v[i] > B)
      {
        break;
      }
      total += v[i];
      ans++;
    }
    cout << ans << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}