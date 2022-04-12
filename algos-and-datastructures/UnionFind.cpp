#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct OptimizedDisjointSet {
  // parent: 각 원소의 루트노드, rank: 각 트리의 높이
  vector<int> parent, rank;

  OptimizedDisjointSet(int n): parent(n), rank(n, 1) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  // u가 속한 트리의 루트 노드의 번호를 리턴
  int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  // u가 속한 트리와 v가 속한 트리를 합침
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rank[u] > rank[v]) swap(u, v);
    // rank[v]가 rank[u] 이상이게 되므로 u를 v의 자식으로 함
    parent[u] = v;
    if (rank[u] == rank[v]) ++rank[v];
  }
};
