// https://www.acmicpc.net/problem/1197
// Find the minimum spanning tree
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int s, e, w;

  Edge(int s, int e, int w):
    s(s), e(e), w(w) {};

  bool operator<(Edge other) const {
    return this->w > other.w;
  }
};

int v, e, ans;
priority_queue<Edge> q;
int parents[10001];

int find(int u) {
  if (parents[u] == u) return u;
  return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
  int pu = find(u);
  int pv = find(v);
  if (pu == pv) return;

  if (pu > pv) {
    swap(pu, pv);
  }
  parents[pv] = pu;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> v >> e;

  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    q.push(Edge(a, b, c));
  }
  for (int i = 0; i <= 10000; i++) {
    parents[i] = i;
  }

  int used_edges = 0;
  while (used_edges < v - 1) {
    Edge eg = q.top();
    q.pop();
    int ps = find(eg.s);
    int pe = find(eg.e);
    if (ps == pe) continue;
    merge(ps, pe);
    ans += eg.w;
    used_edges++;
  }

  cout << ans << "\n";

  return 0;
}