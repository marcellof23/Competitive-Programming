#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  //cin >> T;
  ifstream inputfile;
  ofstream myfile;
  inputfile.open("A1in.txt");
  myfile.open("A1.txt");
  inputfile >> T;
  for (int t = 1; t <= T; t++)
  {
    int str_size, switchs = 0;
    //cin >> str_size;
    inputfile >> str_size;
    string str;
    int x = 0;
    //cin >> str;
    inputfile >> str;
    for (int i = 0; i < str_size; i++)
    {
      if (str[i] == 'F')
      {
        continue;
      }
      if (x == 0 && str[i] == 'X')
      {
        x = 1;
        continue;
      }
      else if (x == 0 && str[i] == 'O')
      {
        x = 2;
        continue;
      }
      if (x == 1 && str[i] == 'O')
      {
        switchs++;
        x = 2;
      }
      else if (x == 2 && str[i] == 'X')
      {
        switchs++;
        x = 1;
      }
    }

    myfile << "Case #" << t << ": " << switchs << "\n";
    cout << "Case #" << t << ": " << switchs << "\n";
  }
  inputfile.close();
  myfile.close();
}