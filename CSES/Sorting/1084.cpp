#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN];
int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  int itr = 0;
  int itr2 = 0;
  int cnt = 0;
  while (itr < n && itr2 < m)
  {
    if ((a[itr] - b[itr2]) > k)
    {
      itr2++;
    }
    else if ((b[itr2] - a[itr]) > k)
    {
      itr++;
    }
    else if (abs(a[itr] - b[itr2]) <= k)
    {
      itr++;
      itr2++;
      cnt++;
    }
    else
    {
      cout << a[itr] << endl;
      cout << b[itr2] << endl;
      itr++;
    }
  }
  cout << cnt << endl;
}