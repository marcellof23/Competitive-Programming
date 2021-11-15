#include <bits/stdc++.h>
using namespace std;

struct node
{
  int val;
  int lvl;
};

int solve(int n, int m)
{
  set<int> visited;
  queue<node> q;
  node nod = {n, 0};
  q.push(nod);
  while (!q.empty())
  {
    node front_node = q.front();
    q.pop();

    if (front_node.val == m)
    {
      return front_node.lvl;
    }

    visited.insert(front_node.val);

    if (front_node.val * 2 == m || front_node.val * 3 == m || front_node.val + 1 == m ||
        front_node.val - 1 == m || front_node.val / 2 == m || front_node.val / 3 == m)
    {
      return front_node.lvl + 1;
    }

    if (visited.find(front_node.val * 3) == visited.end())
    {
      nod.val = front_node.val * 3;
      nod.lvl = front_node.lvl + 1;
      q.push(nod);
    }

    if (visited.find(front_node.val * 2) == visited.end())
    {
      nod.val = front_node.val * 2;
      nod.lvl = front_node.lvl + 1;
      q.push(nod);
    }
    if (visited.find(front_node.val + 1) == visited.end())
    {
      nod.val = front_node.val + 1;
      nod.lvl = front_node.lvl + 1;
      q.push(nod);
    }
    if (visited.find(front_node.val / 3) == visited.end())
    {
      nod.val = front_node.val / 3;
      nod.lvl = front_node.lvl + 1;
      q.push(nod);
    }
    if (visited.find(front_node.val / 2) == visited.end())
    {
      nod.val = front_node.val / 2;
      nod.lvl = front_node.lvl + 1;
      q.push(nod);
    }
    if (front_node.val - 1 >= 0 && visited.find(front_node.val - 1) == visited.end())
    {
      nod.val = front_node.val - 1;
      nod.lvl = front_node.lvl + 1;
      q.push(nod);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << solve(n, m);
}
