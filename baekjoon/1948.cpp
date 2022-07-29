// https://www.acmicpc.net/problem/1948
// Topological sort + Reversing the edges of the graph
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, st, ed, meeting_time, roads;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  cin >> m;
  // start_node -> pair (next_node, time cost from start_node to next_node)
  vector<vector<pair<int, int>> > routes(n + 1);
  vector<vector<pair<int, int>> > reverse_routes(n + 1);
  vector<int> in_degrees(n + 1);
  vector<int> table(n + 1, 0);
  vector<bool> visited(n + 1, false);

  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    routes[a].push_back(make_pair(b, t));
    reverse_routes[b].push_back(make_pair(a, t));
    in_degrees[b]++;
  }

  cin >> st >> ed;

  q.push(st);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto next_pair : routes[now]) {
      int next_node = next_pair.first;
      int cost = next_pair.second;
      in_degrees[next_node]--;
      table[next_node] = max(table[next_node], table[now] + cost);

      if (in_degrees[next_node] == 0) {
        q.push(next_node);
      }
    }
  }

  meeting_time = table[ed];
  q.push(ed);
  visited[ed] = true;

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto next_pair : reverse_routes[now]) {
      int next_node = next_pair.first;
      int cost = next_pair.second;
      if (table[next_node] + cost == table[now]) {
        roads++;
        if (!visited[next_node]) {
          q.push(next_node);
          visited[next_node] = true;
        }
      }
    }
  }

  cout << meeting_time << "\n" << roads;
  return 0;
}