#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int arr[m], arrMin[m], arrMax[m], totMin = 0, totMax = 0;
  memset(arr, 0, sizeof(arr));
  memset(arrMin, 0, sizeof(arrMin));
  memset(arrMax, 0, sizeof(arrMax));
  for (int i = 0; i < m; i++)
  {
    cin >> arr[i];
    arrMin[i] = arr[i];
    arrMax[i] = arr[i];
  }
  int top = m - 1;
  int bot = 0;
  while (n--)
  {
    sort(arrMin, arrMin + m);
    sort(arrMax, arrMax + m);
    if (arrMax[top] <= 0)
    {
      --top;
    }
    if (arrMin[bot] <= 0)
    {

      ++bot;
    }
    totMax += arrMax[top];
    arrMax[top] -= 1;
    totMin += arrMin[bot];
    arrMin[bot] -= 1;
  }
  cout << totMax << " " << totMin << endl;
}
