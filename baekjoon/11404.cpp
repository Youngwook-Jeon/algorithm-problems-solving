// https://www.acmicpc.net/problem/11404
// Floyd-Warshall algo, O(V^3)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 987654321;
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  cin >> m;
  vector<vector<int> > v(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        v[i][j] = 0;
      } else {
        v[i][j] = MAX_VALUE;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a][b] = min(v[a][b], c);
  }

  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      for (int e = 1; e <= n; e++) {
        v[s][e] = min(v[s][e], v[s][k] + v[k][e]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (v[i][j] == MAX_VALUE) {
        cout << "0 ";
      } else {
        cout << v[i][j] << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}