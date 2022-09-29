// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int D[101][100001]; // D[i][j] := 1부터 i번까지의 물품을 사용하여 j 무게까지 버틸 때, 기대할 수 있는 가치합의 최대
int w[101], v[101];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j - w[i] >= 0) {
        D[i][j] = max(D[i - 1][j], D[i - 1][j - w[i]] + v[i]);
      } else {
        D[i][j] = D[i - 1][j];
      }
    }
  }

  cout << D[n][k] << '\n';
  return 0;
}