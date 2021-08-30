#include <bits/stdc++.h>
using namespace std;
#define ll long long

multiset<int> len, pos;
int n, k;
int x;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  pos.insert(0), pos.insert(n), len.insert(n);
  for (int i = 0; i < k; i++)
  {

    cin >> x;
    pos.insert(x);
    auto it = pos.find(x);
    int a = *prev(it), b = *next(it);
    len.erase(len.find(b - a));
    len.insert(x - a), len.insert(b - x);
    cout << *len.rbegin() << " ";
  }
}