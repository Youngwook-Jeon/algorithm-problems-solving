// https://www.acmicpc.net/problem/15591
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, q;
bool visited[5001];
vector<pair<int, int> > graph[5001];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int a, b, r;
    cin >> a >> b >> r;
    graph[a].push_back(make_pair(b, r));
    graph[b].push_back(make_pair(a, r));
  }

  for (int i = 0; i < q; i++) {
    int k, v, res = 0;
    cin >> k >> v;
    for (int i = 1; i <= n; i++) {
      visited[i] = false;
    }
    
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto p : graph[now]) {
        int next = p.first;
        if (visited[next]) continue;
        if (p.second >= k) {
          visited[next] = true;
          q.push(next);
          res++;
        }
      }
    }

    cout << res << '\n';
  }
  return 0;
}