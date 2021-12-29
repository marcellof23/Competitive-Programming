#include <bits/stdc++.h>
using namespace std;

int largest, arrsize;

bool solve(int sum, int i, vector<int> &v)
{
  if (sum == largest)
  {
    return true;
  }
  else if (sum > largest || i == arrsize)
  {
    return false;
  }
  else
  {
    return solve(sum + v[i], i + 1, v) ||
           solve(sum, i + 1, v);
  }
}
string ArrayAddition(int arr[], int arrLength)
{

  vector<int> v;
  arrsize = arrLength - 1;
  for (int i = 0; i < arrLength; i++)
  {
    v.push_back(arr[i]);
  }

  sort(v.begin(), v.end());

  largest = v[arrLength - 1];

  v.pop_back();

  if (solve(0, 0, v))
  {
    return "true";
  }
  else
  {
    return "false";
  }
}

int main(void)
{

  // keep this function call here
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  cout << ArrayAddition(A, n);
  return 0;
}