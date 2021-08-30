#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200005

int main()
{
  static int aa[N];
  int n, k, i;
  ll lower, upper, t, cnt;

  cin >> n >> k;
  for (i = 0; i < n; i++)
    cin >> aa[i];
  lower = 0, upper = 2e18;
  while (upper - lower > 1)
  {
    t = (lower + upper) / 2;
    cnt = 0;
    for (i = 0; i < n; i++)
      if ((cnt += t / aa[i]) >= k)
        break;
    if (cnt >= k)
      upper = t;
    else
      lower = t;
  }
  cout << upper << endl;
  return 0;
}