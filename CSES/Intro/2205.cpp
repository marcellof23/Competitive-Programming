#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n)
{
  for (int i = 0; i < (1 << n); i++)
  {
    int val = (i ^ (i >> 1));
    bitset<64> r(val);
    string s = r.to_string();
    cout << s.substr(64 - n) << endl;
  }
}
int main()
{
  int n;
  cin >> n;
  solve(n);
  return 0;
}