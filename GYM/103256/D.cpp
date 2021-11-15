#include <bits/stdc++.h>
using namespace std;
// #define ll long long

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  int lr[n];
  memset(lr, INT_MIN, sizeof(lr));
  for (int i = 1; i <= m; i++)
  {
    int ll, rr;
    cin >> ll >> rr;
    lr[ll] = max(lr[ll], rr);
  }

  for (int i = 1; i <= n; i++)
  {
    lr[i] = max(lr[i], lr[i - 1]);
  }

  for (int i = 1; i <= q; i++)
  {
    int a, b;
    cin >> a >> b;
    if (b < a)
    {
      swap(a, b);
    }
    if (lr[a] >= b)
    {
      cout << "Yes"
           << "\n";
    }
    else
    {
      cout << "No"
           << "\n";
    }
  }
}
