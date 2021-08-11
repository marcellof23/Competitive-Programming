#include <bits/stdc++.h>
using namespace std;

int x[100], y[100], z[100];
int main()
{

  bool isZero = false;
  int n, totx = 0, toty = 0, totz = 0;
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(z, 0, sizeof(z));
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i] >> z[i];
    totx += x[i];
    toty += y[i];
    totz += z[i];
  }
  if (!totx && !toty && !totz)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}