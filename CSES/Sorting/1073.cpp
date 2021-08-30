#include <bits/stdc++.h>

using namespace std;

int N, k;
multiset<int> ms;

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> k;
    auto it = ms.upper_bound(k);
    if (it != ms.end())
      ms.erase(it);
    ms.insert(k);
  }
  cout << ms.size() << endl;
}
