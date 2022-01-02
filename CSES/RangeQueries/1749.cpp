#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> fen(MAXN);
int arr[MAXN];
int n;

void del(int i)
{
  while (i > 0 && i < n)
  {
    fen[i] += -1;
    i = i + (i & (-i));
  }
}

int find(int v)
{
  int p = 0;
  for (int k = 18; k >= 0; --k)
  {
    if (p + (1 << k) <= n && fen[p + (1 << k)] < v)
    {
      v -= fen[p += (1 << k)];
    }
  }
  return p + 1;
}

int sum(int i)
{
  int ans = 0;
  while (i > 0)
  {
    ans += fen[i];
    i = i - (i & (-i));
  }

  return ans;
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    fen[i] = i & -i;
  }

  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    int pos = find(x);
    del(pos);
    cout << arr[pos] << endl;
  }
}