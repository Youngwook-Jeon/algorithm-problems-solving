// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int D[1000001];

int main() {
  scanf("%d", &n);

  for (int i = 2; i <= n; i++) {
    D[i] = D[i - 1] + 1;
    if (i % 3 == 0) {
      D[i] = min(D[i], D[i / 3] + 1);
    }
    if (i % 2 == 0) {
      D[i] = min(D[i], D[i / 2] + 1);
    }
  }

  printf("%d", D[n]);
  return 0;
}