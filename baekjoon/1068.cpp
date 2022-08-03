// https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>
using namespace std;

int n, root, target, ans;
bool visited[51];

void dfs(int now, vector<vector<int> > &lst) {
  if (now == target) return;
  int children = 0;

  for (int next : lst[now]) {
    if (!visited[next] && next != target) {
      children++;
      visited[next] = true;
      dfs(next, lst);
    }
  }

  if (children == 0) {
    ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  vector<vector<int> > lst(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == -1) {
      root = i;
    } else {
      lst[i].push_back(a);
      lst[a].push_back(i);
    }
  }

  cin >> target;

  visited[root] = true;
  dfs(root, lst);

  cout << ans << "\n";

  return 0;
}