#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n;
  cin >> n;
  int k[n];
  map<int, int> m;
  int ans = 0, l = 1;
  for (int i = 1; i <= n; i++)
  {
    cin >> k[i];
    if (m[k[i]])
    {
      ans = max(ans, i - l);
      cout << l << " " << m[k[i]] + 1 << endl;
      l = max(l, m[k[i]] + 1);
      cout << "l" << l << endl;
    }
    else
    {
      ans = max(ans, i - l + 1);
    }
    m[k[i]] = i;
  }

  ans = max(n - l + 1, ans);

  cout << ans << endl;
}