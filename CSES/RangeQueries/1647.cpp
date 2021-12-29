#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 25;

int st[MAXN][K + 1];
int N, Q;
int arr[MAXN];
int logs[MAXN + 1];

void init()
{
  logs[1] = 0;
  for (int i = 2; i <= MAXN; i++)
    logs[i] = logs[i / 2] + 1;

  for (int i = 0; i < N; i++)
    st[i][0] = arr[i];

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int main()
{
  cin >> N >> Q;
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  init();

  while (Q--)
  {
    int L, R;
    cin >> L >> R;
    --L;
    --R;
    int j = logs[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    cout << minimum << endl;
  }
}