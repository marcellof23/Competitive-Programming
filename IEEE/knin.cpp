#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2569;

int st[NMAX * 4], lazy[NMAX * 4], n;

void build(int i, int l, int r)
{
  st[i] = 0;
  lazy[i] = 0;
  if (r - l < 2)
  {
    return;
  }
}

int main()
{
  int T;
  cin >> T;
}