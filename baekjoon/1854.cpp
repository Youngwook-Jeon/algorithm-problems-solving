// https://www.acmicpc.net/problem/1854
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  int vertex, cost;
  Edge(int vertex, int cost):
    vertex(vertex), cost(cost) {};

  bool operator<(Edge other) const {
    return this->cost > other.cost;
  }
};

int n, m, k;
priority_queue<Edge> q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m >> k;
  vector<priority_queue<int> > dist_q(n + 1);
  vector<vector<int> > mat;
  mat.assign(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    mat[a][b] = c;
  }

  q.push(Edge(1, 0));
  dist_q[1].push(0);
  while (!q.empty()) {
    Edge now = q.top();
    q.pop();
    for (int next_vertex = 1; next_vertex <= n; next_vertex++) {
      if (mat[now.vertex][next_vertex] != 0) {
        if (dist_q[next_vertex].size() < k) {
          dist_q[next_vertex].push(now.cost + mat[now.vertex][next_vertex]);
          q.push(Edge(next_vertex, now.cost + mat[now.vertex][next_vertex]));
        } else if (dist_q[next_vertex].top() > now.cost + mat[now.vertex][next_vertex]) {
          dist_q[next_vertex].pop();
          dist_q[next_vertex].push(now.cost + mat[now.vertex][next_vertex]);
          q.push(Edge(next_vertex, now.cost + mat[now.vertex][next_vertex]));
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist_q[i].size() < k) {
      cout << -1 << "\n";
    } else {
      cout << dist_q[i].top() << "\n";
    }
  }
  return 0;
}