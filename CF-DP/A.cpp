#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int n;
  cin >> n;

  if (n % 2)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << ((ll)2 << (n / 2) - 1) << endl;
  }
}