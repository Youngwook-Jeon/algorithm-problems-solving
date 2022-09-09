// https://www.acmicpc.net/problem/2098
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX_VAL = 987654321;
int n;
int W[16][16];
int D[16][1 << 16];

int solve(int cur, int lst) {
  if (lst == (1 << n) - 1) {
    return W[cur][0] == 0 ? MAX_VAL : W[cur][0];
  }
  if (D[cur][lst] != -1) {
    return D[cur][lst];
  }
  D[cur][lst] = MAX_VAL;

  for (int i = 0; i < n; i++) {
    if ((lst & (1 << i)) == 0 && W[cur][i] != 0) {
      D[cur][lst] = min(D[cur][lst], solve(i, (lst | (1 << i))) + W[cur][i]);
    }
  }
  return D[cur][lst];
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> W[i][j];
    }
  }

  memset(D, -1, sizeof(D));

  cout << solve(0, 1) << '\n';
  return 0;
}