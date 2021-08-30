#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5;

int N, x, l, sum, cnt, a[maxN + 1];

int main()
{
  cin >> N >> x;
  for (int r = 1; r <= N; r++)
  {
    cin >> a[r];
    sum += a[r];
    while (sum > x)
      sum -= a[l++];
    if (sum == x)
      cnt++;
  }
  cout << cnt << endl;
}