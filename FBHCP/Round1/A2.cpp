#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
#define ll long long

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int T;
  cout << "OI";
  fstream f;
  f.open("A2in.txt", ios::in);
  //cin >> T;

  f >> T;
  if (f.eof())
  {
    return 0;
  }

  cout << T << endl;
  f.close();
  return 0;
  // for (int t = 1; t <= T; t++)
  // {
  //   int str_size;
  //   cin >> str_size;
  //   string str;
  //   cin >> str;
  //   for (int i = 0; i < str_size; i++)
  //   {
  //   }
  //   cout << "Case #" << t << ": " << endl;
  // }
}