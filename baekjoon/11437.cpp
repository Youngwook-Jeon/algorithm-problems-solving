// https://www.acmicpc.net/problem/11437
// LCA - basic idea
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
queue<int> q;

void bfs(vector<vector<int> > &lst, vector<int> &parents, vector<bool> &visited, vector<int> &depth) {
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
        parents[next] = now;
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

int solve(int a, int b, vector<vector<int> > &lst, vector<int> &parents, vector<int> &depth) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }

  while (depth[a] != depth[b]) {
    a = parents[a];
  }

  while (a != b) {
    a = parents[a];
    b = parents[b];
  }

  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;

  vector<vector<int> > lst(n + 1);
  vector<int> parents(n + 1);
  vector<bool> visited(n + 1);
  vector<int> depth(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    lst[a].push_back(b);
    lst[b].push_back(a);
  }

  bfs(lst, parents, visited, depth);

  cin >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int ans = solve(a, b, lst, parents, depth);
    cout << ans << "\n";
  }

  return 0;
}