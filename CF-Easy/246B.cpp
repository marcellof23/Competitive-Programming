#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n], tot = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    tot += a[i];
  }
  if (tot % n != 0)
  {
    cout << n - 1 << endl;
  }
  else
  {
    cout << n << endl;
  }

  return 0;
}