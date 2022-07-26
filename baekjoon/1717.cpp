// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<string> ans;

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
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  OptimizedDisjointSet ods(n + 1);
  for (int i = 0; i < m; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 0) {
      ods.merge(a, b);
    } else {
      string s = "NO";
      if (ods.find(a) == ods.find(b)) {
        s = "YES";
      }
      ans.push_back(s);
    }
  }

  for (string s : ans) {
    cout << s << "\n";
  }
  
  return 0;
}