// https://www.acmicpc.net/problem/1256
#include <iostream>
using namespace std;

int n, m ,k;
int D[201][201];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;

  for (int i = 0; i <= 200; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j || j == 0) {
        D[i][j] = 1;
        continue;
      }
      D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
      if (D[i][j] > 1000000000) D[i][j] = 1000000001;
    }
  }

  if (D[n + m][m] < k) {
    cout << -1 << "\n";
  } else {
    while (!(n == 0 && m == 0)) {
      if (D[n - 1 + m][m] >= k) {
        cout << 'a';
        n--;
      } else {
        cout << 'z';
        k -= D[n - 1 + m][m];
        m--;
      }
    }
  }
  return 0;
}