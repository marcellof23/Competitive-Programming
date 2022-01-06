#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

int main()
{
  int n;
  vector<int> v = {7, 7, 8, 9, 1, 1, 1, 2, 2, 3, 3, 3, 4, 5};
  sort(all(v));
  v.resize(unique(all(v)) - v.begin());
  for (auto vv : v)
  {
    cout << vv << endl;
  }
}
