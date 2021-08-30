#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int n, k, tree[MAXN];

void add(int a, int b)
{
  for (; a < MAXN; a += a & -a)
  {
    tree[a] += b;
  }
}

int sum(int p)
{
  int tot = 0;
  for (; p > 0; p -= p & -p)
    tot += tree[p];
  return tot;
}

int search(int x)
{
  int p = 0;
  for (int i = 20; i >= 0; i--)
  {
    if (p + (1 << i) < MAXN && tree[p + (1 << i)] < x)
    {
      p += (1 << i);
      x -= tree[p];
    }
  }
  return p + 1;
}

int main()
{
  cin >> n >> k;
  ++k;
  for (int i = 1; i <= n; i++)
  {
    add(i, 1);
    add(i + n, 1);
  }

  for (int i = 0; i < 18; i++)
  {
    cout << tree[i] << " ";
  }
  cout << endl;
  for (int i = n, end = 0; i >= 1; i--)
  {
    int divi = (k - 1) % i + 1;
    end = search(sum(end) + divi);
    if (end > n)
    {
      end -= n;
    }
    cout << end << " ";
    add(end, -1);
    add(end + n, -1);
  }
  cout << endl;
  return 0;
}