#include <bits/stdc++.h>
using namespace std;
#define ll long long
double grad(int a, int b, int c, int d)
{
  double g;
  g = (d - b) / (c - a);
  return g;
}
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (cross > 0)
    {
      cout << "LEFT\n";
    }
    else if (cross < 0)
    {
      cout << "RIGHT\n";
    }
    else
    {
      cout << "TOUCH\n";
    }
  }
}