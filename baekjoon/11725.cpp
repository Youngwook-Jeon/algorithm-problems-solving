// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[100001];
int ans[100001];

void dfs(int now, vector<vector<int> > &lst) {
  for (int next : lst[now]) {
    if (visited[next]) continue;
    visited[next] = true;
    ans[next] = now;
    dfs(next, lst);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  vector<vector<int> > lst(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    lst[a].push_back(b);
    lst[b].push_back(a);
  }

  visited[1] = true;
  dfs(1, lst);
  
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}