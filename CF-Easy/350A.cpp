#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n;
  cin >> m;
  int arrN[n], arrM[m];
  for (int i = 0; i < n; i++)
  {
    cin >> arrN[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> arrM[i];
  }
  sort(arrN, arrN + n);
  sort(arrM, arrM + m);
  if (arrN[0] * 2 < arrM[0] && arrN[n - 1] < arrM[0])
  {
    cout << max(arrN[0] * 2, arrN[n - 1]) << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}