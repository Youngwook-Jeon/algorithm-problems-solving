// https://www.acmicpc.net/problem/11726
#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 10007;
int n;
int D[1001];

int main() {
  scanf("%d", &n);

  D[1] = 1;
  D[2] = 2;
  for (int i = 3; i <= n; i++) {
    D[i] = (int) (((ll) D[i - 1] + D[i - 2]) % MOD);
  }

  printf("%d", D[n]);
  return 0;
}