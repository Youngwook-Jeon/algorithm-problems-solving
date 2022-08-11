// https://www.acmicpc.net/problem/11438
// LCA - fast skip
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int n, m, max_k;
queue<int> q;

void bfs(vector<vector<int> > &lst, vector<vector<int> > &parents, vector<bool> &visited, vector<int> &depth) {
  visited[1] = true;
  q.push(1);
  int cnt = 0;
  int d = 1;
  int q_size = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    visited[now] = true;
    
    for (int next : lst[now]) {
      if (!visited[next]) {
        parents[0][next] = now;
        q.push(next);
        depth[next] = d;
      }
    }
    cnt++;
    if (cnt == q_size) {
      cnt = 0;
      d++;
      q_size = q.size();
    }
  }
}

int solve(int a, int b, vector<vector<int> > &parents, vector<int> &depth) {
  int ans = 0;

  if (depth[a] > depth[b]) {
    swap(a, b);
  }

  for (int k = max_k; k >= 0; k--) {
    if ((int) pow(2, k) <= depth[b] - depth[a]) {
      if (depth[a] <= depth[parents[k][b]]) {
        b = parents[k][b];
      }
    }
  }

  for (int k = max_k; k >= 0 && a != b; k--) {
    if (parents[k][a] != parents[k][b]) {
      a = parents[k][a];
      b = parents[k][b];
    }
  }

  ans = a;
  if (a != b) {
    ans = parents[0][a];
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;

  vector<vector<int> > lst(n + 1);
  vector<bool> visited(n + 1);
  vector<int> depth(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    lst[a].push_back(b);
    lst[b].push_back(a);
  }

  int tmp = 1;
  while (tmp <= n) {
    tmp <<= 1;
    max_k++;
  }

  // parents[i][j] := j노드의 2^i 번째 부모 노드
  vector<vector<int> > parents(max_k + 1, vector<int>(n + 1));

  bfs(lst, parents, visited, depth);

  for (int i = 1; i <= max_k; i++) {
    for (int j = 1; j <= n; j++) {
      parents[i][j] = parents[i - 1][parents[i - 1][j]];
    }
  }
  
  cin >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int ans = solve(a, b, parents, depth);
    cout << ans << "\n";
  }

  return 0;
}