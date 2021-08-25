#include <bits/stdc++.h>
using namespace std;

const int NMAX = 10;
int N, a, b, answ;

struct event
{
  int time;
  int type;
} events[NMAX];

bool cmp(event A, event B)
{
  return A.time == B.time ? A.type < B.type : A.time < B.time;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    events[2 * i] = {a, 1};
    events[2 * i + 1] = {b, -1};
  }

  sort(events, events + 2 * N, cmp);

  int cur = 0;
  for (int i = 0; i < 2 * N; i++)
  {
    cur += events[i].type;
    answ = max(answ, cur);
  }
  cout << answ << endl;
  for (auto a : events)
  {
    cout << a.time << " " << a.type << endl;
  }
}