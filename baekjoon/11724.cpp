// https://www.acmicpc.net/problem/11724
// Find the number of connected components of a graph
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, ans;

void dfs(int cur, vector<vector<int> > &al, vector<bool> &visited) {
  if (visited[cur]) return;
  visited[cur] = true;

  for (int next : al[cur]) {
    if (!visited[next]) dfs(next, al, visited);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n >> m;
  vector<vector<int> > al(n + 1);
  vector<bool> visited(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    al[a].push_back(b);
    al[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;

    dfs(i, al, visited);
    ans++;
  }

  cout << ans << endl;

  return 0;
}