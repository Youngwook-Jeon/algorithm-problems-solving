// https://www.acmicpc.net/problem/1516
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  vector<int> self(n + 1);
  vector<vector<int> > v(n + 1);
  vector<int> in_degrees(n + 1);
  vector<int> ans(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    self[i] = a;
    while (true) {
      int b;
      cin >> b;
      if (b == -1) {
        break;
      }
      v[b].push_back(i);
      in_degrees[i]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (in_degrees[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int next : v[now]) {
      in_degrees[next]--;
      ans[next] = max(ans[next], ans[now] + self[now]);

      if (in_degrees[next] == 0) {
        q.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] + self[i]) << "\n";
  }
  return 0;
}