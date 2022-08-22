// https://www.acmicpc.net/problem/1947
#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1000000000;
int n;
int D[1000001];

int main() {
  scanf("%d", &n);
  D[1] = 0;
  D[2] = 1;

  for (int i = 3; i <= n; i++) {
    D[i] = (int) (((i - 1) * ((ll) D[i - 1] + D[i - 2])) % MOD);
  }

  printf("%d", D[n]);
  return 0;
}