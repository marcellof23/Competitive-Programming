#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll n, q, mods;
  cin >> n >> q;
  ll arr[n];
  vector<ll> prefArr;
  prefArr.resize(n);
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (i == 0)
    {
      prefArr[i] = arr[i];
    }
    else
    {
      prefArr[i] = arr[i] + prefArr[i - 1];
    }
  }

  mods = prefArr[n - 1];

  while (q--)
  {
    ll que;
    cin >> que;
    auto ans = lower_bound(prefArr.begin(), prefArr.end(), que % mods);
    if (prefArr[ans - prefArr.begin()] <= que % mods)
    {
      cout << ans - prefArr.begin() + 2;
    }
    else
    {
      cout << ans - prefArr.begin() + 1;
    }
    cout << endl;
  }
}