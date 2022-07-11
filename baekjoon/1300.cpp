// https://www.acmicpc.net/problem/1300
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  cin >> k;

  ll s = 1, e = k;
  ll ans = 0;

  while (s <= e) {
    ll mid = (s + e) / 2;
    ll count = 0;

    for (int i = 1; i <= n; i++) {
      count += min(mid / i, (ll) n);
    }

    if (count < k) {
      s = mid + 1;
    } else {
      ans = mid;
      e = mid - 1;
    }
  }

  cout << ans << endl;

  return 0;
}