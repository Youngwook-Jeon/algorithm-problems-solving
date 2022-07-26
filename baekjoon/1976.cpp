// https://www.acmicpc.net/problem/1976
#include <iostream>
#include <vector>
using namespace std;

int n, m;

struct OptimizedDisjointSet {
  vector<int> parent;

  OptimizedDisjointSet(int n): 
    parent(n) {
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }

  int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u > v) {
      int tmp = u;
      u = v;
      v = tmp;
    }
    parent[v] = u;
  }

  bool is_connected(vector<int> &targets) {
    bool ans = true;
    if (targets.size() == 0) {
      return ans;
    }
    
    int root = parent[targets[0]];
    for (int num : targets) {
      if (root != parent[num]) {
        ans = false;
        break;
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> m;

  OptimizedDisjointSet ods(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      if (a == 1) {
        ods.merge(i, j);
      }
    }
  }

  vector<int> targets(m);
  for (int i = 0; i < m; i++) {
    cin >> targets[i];
  }

  string ans = "NO";
  if (ods.is_connected(targets)) {
    ans = "YES";
  }

  cout << ans << "\n";

  return 0;
}