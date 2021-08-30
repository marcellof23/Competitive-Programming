#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct pt
{
  long long x, y;
  pt() {}
  pt(long long _x, long long _y) : x(_x), y(_y) {}
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  long long cross(const pt &p) const { return x * p.y - y * p.x; }
  long long cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long &x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d)
{
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d);
}

bool check_inter(const pt &a, const pt &b, const pt &c, const pt &d)
{
  if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
    return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
  return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
         sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    pt p1 = pt(x1, y1);
    pt p2 = pt(x2, y2);
    pt p3 = pt(x3, y3);
    pt p4 = pt(x4, y4);
    if (check_inter(p1, p2, p3, p4))
    {
      cout << "YES"
           << "\n";
    }
    else
    {
      cout << "NO"
           << "\n";
    }
  }
}