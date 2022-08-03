// https://www.acmicpc.net/problem/1414
#include <iostream>
#include <queue>
using namespace std;

struct Edge {
  int s, e, w;

  Edge(int s, int e, int w):
    s(s), e(e), w(w) {};

  bool operator<(Edge other) const {
    return this->w > other.w;
  }
};

int n, total, min_val;
priority_queue<Edge> q;
int parents[51];
string s;

int find(int u) {
  if (parents[u] == u) return u;
  return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
  int pu = find(u);
  int pv = find(v);
  if (pu == pv) return;

  if (pu > pv) swap(pu, pv);
  parents[pv] = pu;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  getline(cin, s);

  for (int i = 0; i <= 50; i++) {
    parents[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    getline(cin, s);
    for (int j = 1; j <= n; j++) {
      char c = s.at(j - 1);
      int w = 0;
      if (c == '0') {
        continue;
      } else if (c >= 'a') {
        w = c - 'a' + 1;
      } else {
        w = c - 'A' + 27;
      }
      total += w;
      if (i != j) q.push(Edge(i, j, w));
    }
  }

  int used_edges = 0;
  while (!q.empty()) {
    Edge eg = q.top();
    q.pop();
    int ps = find(eg.s);
    int pe = find(eg.e);
    if (ps == pe) continue;
    merge(ps, pe);
    min_val += eg.w;
    used_edges++;
  }

  if (used_edges == n - 1) {
    cout << total - min_val << "\n";
  } else {
    cout << -1 << "\n";
  }
  
  return 0;
}