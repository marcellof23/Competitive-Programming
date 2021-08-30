#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct FenwickTreeMin
{
  vector<int> bit;
  int n;
  const int INF = (int)1e9;
  FenwickTreeMin(int n)
  {
    this->n = n;
    bit.assign(n, INF);
  }
};
int main()
{
}