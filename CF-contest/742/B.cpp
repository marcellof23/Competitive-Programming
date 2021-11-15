#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int arrX[300005];

bool isPowerOfTwo(int n)
{
  if (n == 0)
    return false;

  return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  arrX[0] = 0;
  for (int i = 1; i < 300005; i++)
  {
    arrX[i] = arrX[i - 1] ^ i;
  }
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;

    if (a >= b && b == arrX[a - 1])
    {
      cout << a << endl;
      continue;
    }
    if (a > b)
    {
      cout << a + 1 << endl;
    }
    else if (a == b)
    {
      if (isPowerOfTwo(a) && a != 2)
      {
        cout << a + 2 << endl;
      }
      else
      {
        cout << a + 1 << endl;
      }
    }
    else
    {
      cout << a + 1 << endl;
    }
  }
}