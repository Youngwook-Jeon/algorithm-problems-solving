// https://www.acmicpc.net/problem/1010
#include <iostream>
using namespace std;

int t;
int D[30][30];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> t;

  for (int i = 0; i < 30; i++) {
    for (int j = 0; j <= i; j++) {
      D[i][j] = 1;
    }
  }

  for (int i = 1; i < 30; i++) {
    for (int j = 1; j <= i - 1; j++) {
      D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
    }
  }

  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    cout << D[m][n] << "\n";
  }

  return 0;
}