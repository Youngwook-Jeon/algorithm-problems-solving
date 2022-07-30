// https://www.acmicpc.net/problem/11657
// Bellman-Ford algo, O(VE)
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX_VALUE = 987654321;
int n, m;
bool hasNegativeCycle = false;

struct Edge {
  int s, e, t;

  Edge(int s, int e, int t):
    s(s), e(e), t(t) {};
};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  vector<Edge> lst(m, Edge(0, 0, 0));
  vector<ll> dist(n + 1, MAX_VALUE);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    lst[i] = Edge(a, b, c);
  }

  dist[1] = 0LL;

  for (int i = 0; i < n - 1; i++) {
    for (Edge eg : lst) {
      if (dist[eg.s] != MAX_VALUE && dist[eg.e] > dist[eg.s] + eg.t) {
        dist[eg.e] = dist[eg.s] + eg.t;
      }
    }
  }

  for (Edge eg : lst) {
    if (dist[eg.s] != MAX_VALUE && dist[eg.e] > dist[eg.s] + eg.t) {
      hasNegativeCycle = true;
    }
  }

  if (hasNegativeCycle) {
    cout << -1 << "\n";
  } else {
    for (int i = 2; i <= n; i++) {
      if (dist[i] != MAX_VALUE) {
        cout << dist[i] << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }
  return 0;
}