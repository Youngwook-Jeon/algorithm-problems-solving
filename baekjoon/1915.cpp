// https://www.acmicpc.net/problem/1915
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  cin.ignore();
  vector<vector<int> > D(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (int j = 0; j < m; j++) {
      D[i][j] = s[j] - '0';
      if (D[i][j] == 1 && i > 0 && j > 0) {
        D[i][j] = min(D[i - 1][j - 1], min(D[i][j - 1], D[i - 1][j])) + 1;
      }

      if (ans < D[i][j]) {
        ans = D[i][j];
      }
    }
  }

  cout << ans * ans << '\n';
  return 0;
}