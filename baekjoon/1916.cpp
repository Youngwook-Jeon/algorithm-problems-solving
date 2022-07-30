// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int vertex, cost;
  Edge(int vertex, int cost):
    vertex(vertex), cost(cost) {};

  bool operator<(Edge other) const {
    return this->cost > other.cost;
  }
};

const int MAX_VALUE = 987654321;
int n, m, st, ed;
priority_queue<Edge> q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  cin >> m;
  vector<bool> visited(n + 1);
  vector<int> cost_table(n + 1, MAX_VALUE);
  vector<vector<Edge> > lst(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    lst[a].push_back(Edge(b, c));
  }
  cin >> st >> ed;

  cost_table[st] = 0;
  q.push(Edge(st, 0));

  while (!q.empty()) {
    Edge now = q.top();
    q.pop();
    if (visited[now.vertex]) continue;
    visited[now.vertex] = true;
    for (Edge next : lst[now.vertex]) {
      if (!visited[next.vertex] && cost_table[next.vertex] > cost_table[now.vertex] + next.cost) {
        cost_table[next.vertex] = cost_table[now.vertex] + next.cost;
        q.push(Edge(next.vertex, cost_table[next.vertex]));
      }
    }
  }

  cout << cost_table[ed] << "\n";
  
  return 0;
}