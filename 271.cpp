#include <bits/stdc++.h>
using namespace std;

int main()
{
  string n;
  cin >> n;
  for (int i = stoi(n) + 1; i < 9013; i++)
  {
    string currStr = to_string(i);
    int cnt = 0;
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        if (j != k && currStr[j] != currStr[k])
        {
          cnt++;
        }
        if (cnt == 12)
        {
          cout << i << endl;
          return 0;
        }
      }
    }
  }
}