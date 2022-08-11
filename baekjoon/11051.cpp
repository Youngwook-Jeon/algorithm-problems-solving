// https://www.acmicpc.net/problem/11051
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
int n, k;

int main() {
  scanf("%d %d", &n, &k);
  vector<vector<int> > D(n + 1, vector<int>(n + 1, 1));

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      D[i][j] = D[i - 1][j] % MOD + D[i - 1][j - 1] % MOD;
    }
  }

  cout << D[n][k] % MOD << "\n";

  return 0;
}