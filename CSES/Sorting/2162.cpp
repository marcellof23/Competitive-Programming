#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n;
  int a = 1, b = 0;
  while (n > 0)
  {
    for (int i = 2; i <= n; i += 2)
    {
      cout << a * i + b << ' ';
    }
    if (n & 1)
      cout << a + b << ' ', b += a;
    else
      b -= a;
    a <<= 1;
    n >>= 1;
  }
}
