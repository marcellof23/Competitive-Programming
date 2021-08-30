#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5 + 5;
struct query
{
  int a;
  int b;
  int diff;
} arr[MAXN];

bool cmp(query q1, query q2)
{
  // if (q1.diff != q2.diff)
  // {
  //   return q1.diff > q2.diff;
  // }
  // if (q1.b != q2.b)
  // {
  //   return q1.b < q2.b;
  // }
  return q1.a < q2.a;
}

int n;

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int a, d;
    cin >> a >> d;
    arr[i].a = a;
    arr[i].b = d;
    arr[i].diff = d - a;
  }
  sort(arr, arr + n, cmp);

  ll curr = 0;
  ll reward = 0;
  for (int i = 0; i < n; i++)
  {
    curr += arr[i].a;

    reward += (arr[i].b - curr);
    // cout << reward << endl;
  }
  cout << reward << endl;
}