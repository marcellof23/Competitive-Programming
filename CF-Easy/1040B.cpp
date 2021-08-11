#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, ans;
  cin >> n >> k;
  if (n % (k * 2 + 1) == 0)
  {
    ans = n / (k * 2 + 1);
    cout << ans << endl;
    int pref = k + 1;
    for (int i = 1; i <= ans; i++)
    {
      cout << pref << " ";
      pref += (2 * k + 1);
    }
    cout << endl;
  }
  else
  {
    ans = n / (k * 2 + 1) + 1;
    cout << ans << endl;
    int pref;
    int offset = n % (2 * k + 1);
    if (offset > k + 1)
    {
      pref = offset - k;
    }
    else
    {
      pref = 1;
    }
    for (int i = 1; i <= ans; i++)
    {
      cout << pref << " ";
      pref += (2 * k + 1);
    }
    cout << endl;
  }
}