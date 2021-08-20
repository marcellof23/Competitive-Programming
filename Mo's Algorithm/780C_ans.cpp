#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
struct node
{
  int val;
  node *l, *r;
  node() {}
  node(node *_l, node *_r, int _v)
  {
    l = _l;
    r = _r;
    val = _v;
  }
};

int arr[MAXN], n;
node *roots[MAXN];

void build(node *n, int low, int high)
{
}
int main()
{
}