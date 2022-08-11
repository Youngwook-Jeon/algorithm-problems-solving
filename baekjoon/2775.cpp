// https://www.acmicpc.net/problem/2775
#include <iostream>
using namespace std;

int t;
int D[15][15];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> t;

  for (int i = 1; i < 15; i++) {
    D[0][i] = i;
  }

  for (int k = 1; k < 15; k++) {
    for (int b = 1; b < 15; b++) {
      int su = 0;
      for (int n = 1; n <= b; n++) {
        su += D[k - 1][n];
      }
      D[k][b] = su;
    }
  }

  for (int i = 0; i < t; i++) {
    int k, n;
    cin >> k;
    cin >> n;
    cout << D[k][n] << "\n";
  }

  return 0;
}