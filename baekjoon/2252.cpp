// https://www.acmicpc.net/problem/2252
// Topological sort
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> ans;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  vector<vector<int> > v(n + 1);
  vector<int> in_degrees(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    in_degrees[b]++;
  }

  for (int i = 1; i <= n; i++) {
    if (in_degrees[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int now = q.front();
    ans.push_back(now);
    q.pop();
    for (int next : v[now]) {
      in_degrees[next]--;
      if (in_degrees[next] == 0) {
        q.push(next);
      }
    }
  }

  for (int num : ans) {
    cout << num << " ";
  }
  return 0;
}