// https://www.acmicpc.net/problem/2193
#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll D[91];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  D[1] = 1;
  D[2] = 1;

  for (int i = 3; i <= n; i++) {
    D[i] = D[i - 1] + D[i - 2];
  }

  cout << D[n] << '\n';
  return 0;
}