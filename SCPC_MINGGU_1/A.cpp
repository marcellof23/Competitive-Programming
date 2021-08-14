#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int L, N;
    cin >> L >> N;
    int arr[N], selisih[N - 1];
    int maxSelisih = -(1e9 + 7);

    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 0; i < N - 1; i++)
    {
      maxSelisih = max(maxSelisih, arr[i + 1] - arr[i]);
    }
    int leftseg = arr[0] - 1;
    int rightseg = L - arr[N - 1];
    int midseg = maxSelisih * 2 / 3;
    if (N == 1)
    {
      midseg = 0;
    }

    if (midseg > leftseg && midseg > 2 * rightseg)
    {
      // cout << "a";
      cout << midseg << endl;
    }
    else
    {
      // cout << "b";
      // cout << leftseg << " " << rightseg << endl;
      cout << max(leftseg, 2 * rightseg) << endl;
    }
  }
}