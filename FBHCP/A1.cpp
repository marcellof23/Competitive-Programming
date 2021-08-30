#include <bits/stdc++.h>
using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVXYZ";

bool checkVowel(char c)
{
  return (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O');
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    string str;
    cin >> str;
    int s_size = str.size();
    multiset<char> ms;
    for (int i = 0; i < s_size; i++)
    {
      ms.insert(str[i]);
    }
    int maxVowel = -1;
    int cntVowel = 0;
    int maxConsonant = -1;
    int cntConsonant = 0;
    for (int i = 0; i < s_size; i++)
    {
      if (checkVowel(str[i]))
      {
        cntVowel++;
      }
      else
      {
        cntConsonant++;
      }
    }
    for (int i = 0; i < alpha.size(); i++)
    {
      if (checkVowel(alpha[i]))
      {
        maxVowel = max(maxVowel, (int)ms.count(alpha[i]));
      }
      else
      {
        maxConsonant = max(maxConsonant, (int)ms.count(alpha[i]));
      }
      // cout << alpha[i] << " " << ms.count(alpha[i]) << endl;
    }

    // cout << maxVowel << " " << maxConsonant;
    // cout << cntVowel << " " << cntConsonant;
    cout << "Case #" << t << ": " << min((cntConsonant + 2 * (cntVowel - maxVowel)), (cntVowel + 2 * (cntConsonant - maxConsonant))) << "\n";
  }
}