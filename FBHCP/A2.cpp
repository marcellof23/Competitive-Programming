#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> d(305);

string alpha = "ABCDEFGHIJKLMNOPQRSTUVXYZ";

void dijkstra(int s, int n, vector<pair<int, int>> adj[105])
{
  d.assign(n, INT_MAX);
  d[s] = 0;
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty())
  {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : adj[v])
    {
      int to = edge.first;
      int len = edge.second;

      if (d[v] + len < d[to])
      {
        d[to] = d[v] + len;
        q.push({d[to], to});
      }
    }
  }
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
    int k;
    int dist[26][26];
    vector<pair<int, int>> adj[105];
    set<char> sc;
    cin >> str;
    cin >> k;

    int s_size = str.size();
    for (int i = 0; i < s_size; i++)
    {
      sc.insert(str[i]);
    }

    for (int i = 0; i < k; i++)
    {
      string query;
      cin >> query;
      sc.insert(query[0]);
      sc.insert(query[1]);
      adj[query[0] - 'A'].push_back({query[1] - 'A', 1});
    }

    for (int i = 0; i < 26; i++)
    {
      dijkstra(i, 26, adj);
      for (int j = 0; j < 26; j++)
      {
        dist[i][j] = d[j];
      }
    }

    int sc_size = sc.size();
    vector<char> alp;
    for (auto it = sc.begin(); it != sc.end(); it++)
    {
      alp.push_back(*it);
    }

    long long minDist = INT64_MAX;
    bool isAns = false;
    for (int i = 0; i < sc_size; i++)
    {
      long long tot = 0;
      int cnt = 0;
      bool masuk = false;
      for (int j = 0; j < s_size; j++)
      {
        if (dist[str[j] - 'A'][alp[i] - 'A'] != INT_MAX)
        {
          cnt++;
          tot += dist[str[j] - 'A'][alp[i] - 'A'];
        }
      }

      if (cnt == s_size)
      {
        minDist = min(minDist, tot);
        isAns = true;
      }

      // cout << minDist << endl;
    }
    if (!isAns)
    {
      cout << "Case #" << t << ": " << -1 << "\n";
      continue;
    }
    cout << "Case #" << t << ": " << minDist << "\n";
  }
}