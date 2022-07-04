// https://www.acmicpc.net/problem/13023
// Find out if there is a subpart of the graph with a length of 4
#include <iostream>
#include <vector>
using namespace std;

const int TARGET_DEPTH = 5;
int n, m, ans;

void dfs(int cur, int depth, vector<vector<int> > &al, vector<bool> &visited) {
  if (depth == TARGET_DEPTH || ans == 1) {
    ans = 1;
    return;
  }

  visited[cur] = true;
  for (int next : al[cur]) {
    if (!visited[next]) dfs(next, depth + 1, al, visited);
  }
  visited[cur] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n >> m;

  vector<vector<int> > al(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    al[a].push_back(b);
    al[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    vector<bool> visited(n);
    if (ans == 1) {
      break;
    }
    dfs(i, 1, al, visited);
  }

  cout << ans << endl;
  return 0;
}