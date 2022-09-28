// https://www.acmicpc.net/problem/10021
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

struct Edge {
  int s, e;
  ll v;

  bool operator< (Edge other) const {
    return this->v > other.v;
  }
};

int n, c;
ll res;
priority_queue<Edge> q;
pair<int, int> loc[2000];
int parents[2000];

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

  cin >> n >> c;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    loc[i] = make_pair(a, b);
    parents[i] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll dx = ((ll)loc[i].first - loc[j].first) * ((ll)loc[i].first - loc[j].first);
      ll dy = ((ll)loc[i].second - loc[j].second) * ((ll)loc[i].second - loc[j].second);
      q.push({i, j, dx + dy});
    }
  }

  int used_edges = 0;
  while (!q.empty()) {
    Edge ed = q.top();
    q.pop();
    if (ed.v < c) continue;
    int s = find(ed.s);
    int e = find(ed.e);
    if (s == e) continue;
    merge(s, e);
    res += ed.v;
    used_edges++;
    if (used_edges == n - 1) break;
  }
  if (used_edges < n - 1) res = -1;

  cout << res << '\n';
  return 0;
}