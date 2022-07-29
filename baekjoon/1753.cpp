// https://www.acmicpc.net/problem/1753
// Dijkstra - O(ElogV)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  int vertex;
  int weight;

  Edge(int vertex, int weight):
    vertex(vertex), weight(weight) {};

  bool operator<(const Edge ed) const {
    return this->weight > ed.weight;
  }
};

const int MAX_VALUE = 987654321;
int v, e, st;
priority_queue<Edge> q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> v >> e;
  cin >> st;
  vector<vector<pair<int, int>> > lst(v + 1);
  vector<bool> visited(v + 1);
  vector<int> table(v + 1, MAX_VALUE);
  table[st] = 0;

  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    lst[a].push_back(make_pair(b, w));
  }

  q.push(Edge(st, 0));

  while (!q.empty()) {
    Edge now = q.top();
    q.pop();
    if (visited[now.vertex]) continue;
    visited[now.vertex] = true;
    for (auto next_pair: lst[now.vertex]) {
      int next_node = next_pair.first;
      int weight = next_pair.second;
      if (table[next_node] > table[now.vertex] + weight) {
        table[next_node] = table[now.vertex] + weight;
        q.push(Edge(next_node, table[next_node]));
      }
    }
  }

  for (int i = 1; i <= v; i++) {
    if (table[i] != MAX_VALUE) {
      cout << table[i] << "\n";
    } else {
      cout << "INF" << "\n";
    }
  }
  return 0;
}