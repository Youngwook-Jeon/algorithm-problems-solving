// https://www.acmicpc.net/problem/1389
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 987654321;
int n, m;

int main(){
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  vector<vector<int> > v(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        v[i][j] = MAX_VALUE;
        v[j][i] = MAX_VALUE;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a][b] = 1;
    v[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      for (int e = 1; e <= n; e++) {
        v[s][e] = min(v[s][e], v[s][k] + v[k][e]);
      }
    }
  }

  int ans = 1;
  int su = MAX_VALUE;
  for (int i = 1; i <= n; i++) {
    int temp = 0;
    for (int j = 1; j <= n; j++) {
      temp += v[i][j];
    }
    if (temp < su) {
      su = temp;
      ans = i;
    }
  }

  cout << ans << "\n";
  return 0;
}