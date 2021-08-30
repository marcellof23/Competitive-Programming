#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int max = 2e5 + 5;
ll n, x, pre, cnt;
map<ll, int> m;

int main()
{
  m[0] = 1;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    int q;
    cin >> q;
    pre += q;
    cnt += m[pre - x];
    m[pre]++;
  }
  cout << cnt << endl;
}