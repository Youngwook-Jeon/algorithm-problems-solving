// https://www.acmicpc.net/problem/2342
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX_VAL = 987654321;
int step = 1, n, ans;
int power_itoj[5][5] = {{0, 2, 2, 2, 2}, {2, 1, 3, 4, 3}, {2, 3, 1, 3, 4}, {2, 4, 3, 1, 3}, {2, 3, 4, 3, 1}};
int D[100001][5][5];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  for (int i = 0; i <= 100000; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        D[i][j][k] = MAX_VAL;
      }
    }
  }

  D[0][0][0] = 0;

  while (true) {
    cin >> n;
    if (n == 0) break;
    
    for (int i = 0; i < 5; i++) {
      if (n == i) continue;

      for (int j = 0; j < 5; j++) {
        D[step][i][n] = min(D[step - 1][i][j] + power_itoj[j][n], D[step][i][n]);
      }
    }

    for (int j = 0; j < 5; j++) {
      if (n == j) continue;

      for (int i = 0; i < 5; i++) {
        D[step][n][j] = min(D[step - 1][i][j] + power_itoj[i][n], D[step][n][j]);
      }
    }

    step++;
  }

  ans = INT_MAX;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ans = min(ans, D[step - 1][i][j]);
    }
  }

  cout << ans << '\n';
  return 0;
}