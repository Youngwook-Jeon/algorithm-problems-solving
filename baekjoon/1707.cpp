// https://www.acmicpc.net/problem/1707
// Find out whether the given graph is bipartite or not.
#include <iostream>
#include <vector>
using namespace std;

int k, v, e;
bool isBipartite = true;

void dfs(int node, vector<vector<int> > &al, vector<bool> &visited, vector<int> &table) {
  if (visited[node]) return;

  visited[node] = true;
  for (int next : al[node]) {
    if (!visited[next]) {
      table[next] = (table[node] + 1) % 2;
      dfs(next, al, visited, table);
    } else {
      if (table[next] == table[node]) {
        isBipartite = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k;
  vector<string> ans(k);
  for (int i = 0; i < k; i++) {
    cin >> v >> e;
    vector<vector<int> > al(v + 1);
    vector<bool> visited(v + 1);
    vector<int> table(v + 1);
    isBipartite = true;

    for (int j = 0; j < e; j++) {
      int a, b;
      cin >> a >> b;
      al[a].push_back(b);
      al[b].push_back(a);
    }

    for (int j = 0; j <= v; j++) {
      if (isBipartite) {
        dfs(j, al, visited, table);
      } else {
        break;
      }
    }

    if (isBipartite) {
      ans[i] = "YES";
    } else {
      ans[i] = "NO";
    }
  }

  for (string s : ans) {
    cout << s << "\n";
  }

  return 0;
}