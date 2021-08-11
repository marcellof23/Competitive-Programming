#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  string str1, str2;
  int tot1 = 0, tot2 = 0;
  cin >> str1;
  cin >> str2;
  for (int i = 0; i < str1.size(); i++)
  {
    str1[i] = toupper(str1[i]);
    str2[i] = toupper(str2[i]);
    if (str1[i] == str2[i])
    {
      tot1 += str1[i] - 'A';
      tot2 += str2[i] - 'A';
    }
    else if (str1[i] - 'A' > str2[i] - 'A')
    {
      cout << "1" << endl;
      return 0;
    }
    else
    {
      cout << "-1" << endl;
      return 0;
    }
  }
  if (tot1 == tot2)
  {
    cout << "0" << endl;
  }
  else if (tot1 > tot2)
  {
    cout << "1" << endl;
  }
  else
  {
    cout << "-1" << endl;
  }
}