#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;

  long long pref[n + 5];

  memset(pref, 0, sizeof(pref));

  for (int i = 1; i <= n; i++)
  {
    long long x;
    cin >> x;
    pref[i] = pref[i - 1];
    pref[i] += x;
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << endl;
  }
}