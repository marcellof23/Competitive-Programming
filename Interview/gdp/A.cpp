#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int l[MAXN], r[MAXN];
int main()
{
  int n;
  cin >> n;
  char arr[MAXN];

  for (int i = 1; i <= MAXN; i++)
  {
    arr[i] = ' ';
  }

  for (int i = 1; i <= n; i++)
  {
    int left, right;
    cin >> left >> right;
    if (arr[right] == 'l')
    {
      arr[right] = 'l';
      arr[left] = 'l';
    }
    if (arr[left] == 'r')
    {
      arr[left] = 'l';
      arr[right] = 'r';
    }
    else
    {
      arr[left] = 'l';
      arr[right] = 'r';
    }
  }

  char currchar = ' ';
  int idx = 1;
  vector<pair<int, int>> ans;
  for (int i = 1; i <= MAXN; i++)
  {
    if (currchar == ' ' && arr[i] == 'l')
    {
      idx = i;
      currchar = 'l';
    }
    else if ((arr[i] == 'l' || arr[i] == ' ') && currchar == 'l')
      continue;
    else if (arr[i] == 'r' && currchar == 'l')
    {
      ans.push_back({idx, i});
      currchar = ' ';
    }
  }

  // for (int i = 1; i <= 20; i++)
  // {
  //   cout << arr[i] << " ";
  // }

  // cout << endl;

  for (auto a : ans)
  {
    cout << a.first << " " << a.second << endl;
  }
}