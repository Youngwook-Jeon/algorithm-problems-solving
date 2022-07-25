// https://www.acmicpc.net/problem/1325
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int dfs(int start, vector<bool> &visited, vector<vector<int> > &v) {
  if (visited[start]) return 0;
  visited[start] = true;
  int md = 1;
  for (int next : v[start]) {
    md += dfs(next, visited, v);
  }
  return md;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  vector<vector<int> > v(n + 1);
  vector<int> ans(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[b].push_back(a);
  }

  int mx = -1;

  for (int i = 1; i <= n; i++) {
    vector<bool> visited(n + 1, false);
    int cnt = dfs(i, visited, v);
    ans[i] = cnt;
    mx = max(mx, cnt);
  }

  for (int i = 0; i <= n; i++) {
    if (ans[i] == mx) {
      cout << i << " ";
    }
  }
  return 0;
}