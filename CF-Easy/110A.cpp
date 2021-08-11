#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long s;
  bool empat = false, tujuh = false;
  cin >> s;
  int cnt = 0;
  while (s > 0)
  {
    int curr = s % 10;
    if (curr == 4 || curr == 7)
    {
      cnt++;
    }
    s /= 10;
  }
  (cnt == 4 || cnt == 7) ? cout << "YES" << endl : cout << "NO" << endl;
}
