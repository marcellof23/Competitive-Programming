#include <bits/stdc++.h>
using namespace std;

struct item
{
  int key, prior;
  item *l, *r;
  item() {}
  item(int key) : key(key), prior(rand()), l(NULL), r(NULL) {}
};
typedef item *pitem;

void split(pitem t, int key, pitem &l, pitem &r)
{
  if (!t)
    l = r = NULL;
  else if (t->key <= key)
    split(t->r, key, t->r, r), l = t;
  else
    split(t->l, key, l, t->l), r = t;
}

int main()
{
}