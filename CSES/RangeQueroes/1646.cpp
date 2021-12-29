#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;

  int pref[n];

  memset(pref, 0, sizeof(pref));

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (i == 0)
      pref[i] = x;
    else
      pref[i] += (pref[i - 1] + x);
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int left;
    l == ? left = 0 : left = pref[l - 1];
    cout << pref[r] - left << endl;
  }
}