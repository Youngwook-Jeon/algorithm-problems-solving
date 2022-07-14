// https://www.acmicpc.net/problem/11689
// 서로소의 갯수 찾기
#include <iostream>
using namespace std;
typedef long long ll;

ll n, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  ans = n;

  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans -= (ans / i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }

  if (n > 1) {
    ans -= (ans / n);
  }

  cout << ans << "\n";

  return 0;
}