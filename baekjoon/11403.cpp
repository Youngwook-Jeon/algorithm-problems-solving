// https://www.acmicpc.net/problem/11403
#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  vector<vector<bool> > v(n + 1, vector<bool>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      v[i][j] = a;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      for (int e = 1; e <= n; e++) {
        v[s][e] = (v[s][e] || (v[s][k] && v[k][e]));
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}