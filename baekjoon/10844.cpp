// https://www.acmicpc.net/problem/10844
#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1000000000;
int n, ans;
int D[101][10];

int main() {
  scanf("%d", &n);

  for (int i = 1; i < 10; i++) {
    D[1][i] = 1;
  }

  for (int i = 2; i <= 100; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0) {
        D[i][j] = ((ll) (D[i - 1][j + 1])) % MOD;
      } else if (j == 9) {
        D[i][j] = ((ll) (D[i - 1][j - 1])) % MOD;
      } else {
        D[i][j] = ((ll) (D[i - 1][j + 1]) + D[i - 1][j - 1]) % MOD;
      }
    }
  }

  for (int i = 0; i <= 9; i++) {
    ans = (int) ((ans + (ll)D[n][i]) % MOD);
  }
  printf("%d", ans);
  return 0;
}