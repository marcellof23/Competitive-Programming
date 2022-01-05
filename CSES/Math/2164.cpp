#include <bits/stdc++.h>
using namespace std;

int josephus_query(int n, int k)
{
  if (n == 1)
  {
    return 1;
  }
  else if (n & 1)
  {
    return (k <= (n + 1) / 2) ? (2 * k % n) : (2 * josephus_query(n / 2, k - (n + 1) / 2) + 1);
  }
  else
  {
    return (k <= n / 2) ? (2 * k) : (2 * josephus_query(n / 2, k - n / 2) - 1);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--)
  {
    int n, k;
    cin >> n >> k;
    cout << josephus_query(n, k) << "\n";
  }
}