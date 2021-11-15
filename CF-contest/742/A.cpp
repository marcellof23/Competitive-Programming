#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--)
  {
    int x;
    cin >> x;
    string str;
    cin >> str;
    for (int i = 0; i < x; i++)
    {
      if (str[i] == 'D')
      {
        cout << "U";
      }
      else if (str[i] == 'U')
      {
        cout << "D";
      }
      else
      {
        cout << str[i];
      }
    }
    cout << endl;
  }
}