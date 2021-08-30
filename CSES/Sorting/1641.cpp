#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int N, X, r;
pair<int, int> arr[MAXN];
int main()
{
  cin >> N >> X;
  for (int i = 0; i < N; i++)
  {
    int q;
    cin >> q;
    arr[i] = {q, i + 1};
  }
  sort(arr, arr + N);

  int ans;
  for (int i = 0; i < N; i++)
  {
    ans = X - arr[i].first;
    r = N - 1;
    for (int l = i + 1; l < r; l++)
    {
      while (l + 1 < r && arr[l].first + arr[r].first > ans)
        r--;
      if (arr[l].first + arr[r].first == ans)
      {
        cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
