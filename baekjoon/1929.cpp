// https://www.acmicpc.net/problem/1929
// 에라토스테네스의 체
#include <iostream>
#include <vector>
using namespace std;

int m, n;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> m >> n;
  vector<int> v(n + 1, 1);
  v[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      if (v[j] == 0) continue;

      v[j] = 0;
    }
  }

  for (int i = m; i <= n; i++) {
    if (v[i] == 1) {
      cout << i << "\n";
    }
  }

  return 0;
}