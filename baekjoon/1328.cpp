#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
int n, l, r;
// D[n][l][r] := n개의 건물, 왼쪽에서 l개, 오른쪽에서 r개를 관찰하는 경우의 수
int D[101][101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> l >> r;
  D[1][1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        D[i][j][k] = (int) (((ll) D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + (ll) D[i - 1][j][k] * (i - 2)) % MOD);
      }
    }
  }

  cout << D[n][l][r] << '\n';
  return 0;
}