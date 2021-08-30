#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
struct pt
{
  ll x, y, id;
};

struct cmp_x
{
  bool operator()(const pt &a, const pt &b) const
  {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  }
};

struct cmp_y
{
  bool operator()(const pt &a, const pt &b) const
  {
    return a.y < b.y;
  }
};

ll mindist = LLONG_MAX;
ll n;
vector<pt> a;
pair<ll, ll> best_pair;

void upd_ans(const pt &a, const pt &b)
{
  ll dist = ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  if (dist < mindist)
  {
    mindist = dist;
    best_pair = {a.id, b.id};
  }
}

vector<pt> t;

void rec(int l, int r)
{
  if (r - l <= 3)
  {
    for (int i = l; i < r; ++i)
    {
      for (int j = i + 1; j < r; ++j)
      {
        upd_ans(a[i], a[j]);
      }
    }
    sort(a.begin() + l, a.begin() + r, cmp_y());
    return;
  }

  ll m = (l + r) >> 1;
  ll midx = a[m].x;
  rec(l, m);
  rec(m, r);

  merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
  copy(t.begin(), t.begin() + r - l, a.begin() + l);

  ll tsz = 0;
  for (int i = l; i < r; ++i)
  {
    if (abs(a[i].x - midx) < mindist)
    {
      for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
        upd_ans(a[i], t[j]);
      t[tsz++] = a[i];
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  a.resize(n);
  t.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].x >> a[i].y;
  }
  sort(a.begin(), a.end(), cmp_x());
  rec(0, n);
  cout << mindist << endl;
}
