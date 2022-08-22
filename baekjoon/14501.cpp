// https://www.acmicpc.net/problem/14501
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int T[16], P[16], D[16];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> T[i] >> P[i];
  }

  for (int i = n; i > 0; i--) {
    if (i + T[i] > n + 1) {
      D[i] = D[i + 1];
    } else {
      D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
    }
  }

  cout << D[1] << '\n';

  return 0;
}