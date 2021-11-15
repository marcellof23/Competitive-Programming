#include <bits/stdc++.h>
using namespace std;

double nc2(int n)
{
  return (n) * (n - 1) / 2;
}

int main()
{
  int N;
  double P;

  cin >> N;
  cin >> P;

  if (abs(P - (double)0) <= 0.00001)
  {
    cout << 0 << endl;
    return 0;
  }

  for (int m = 0; m <= N - 2; m++)
  {
    double candidate = nc2(N - m) / nc2(N);
    // cout << candidate << endl;
    if (candidate >= (double)1 - P)
    {
      cout << m << endl;
      return 0;
    }
  }
}