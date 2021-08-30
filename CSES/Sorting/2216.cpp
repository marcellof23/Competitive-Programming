#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAarrN = 2e5 + 5;
int n, m, pos[MAarrN], arr[MAarrN];

int upd(int a, int b, int &cnt)
{
  if (pos[arr[a] - 1] <= pos[arr[a]] && b < pos[arr[a] - 1])
    cnt++;
  if (pos[arr[a] - 1] > pos[arr[a]] && b >= pos[arr[a] - 1])
    cnt--;
  if (pos[arr[a] + 1] >= pos[arr[a]] && b > pos[arr[a] + 1])
    cnt++;
  if (pos[arr[a] + 1] < pos[arr[a]] && b <= pos[arr[a] + 1])
    cnt--;
  pos[arr[a]] = b;

  if (pos[arr[b] - 1] <= pos[arr[b]] && a < pos[arr[b] - 1])
    cnt++;
  if (pos[arr[b] - 1] > pos[arr[b]] && a >= pos[arr[b] - 1])
    cnt--;
  if (pos[arr[b] + 1] >= pos[arr[b]] && a > pos[arr[b] + 1])
    cnt++;
  if (pos[arr[b] + 1] < pos[arr[b]] && a <= pos[arr[b] + 1])
    cnt--;
  pos[arr[b]] = a;

  swap(arr[a], arr[b]);
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  pos[n + 1] = n + 1;

  int cnt = 0, prev = 0;
  for (int i = 1; i <= n; i++)
  {
    if (prev > pos[i])
      cnt++;
    prev = pos[i];
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    upd(a, b, cnt);
    cout << cnt + 1 << endl;
  }
}
