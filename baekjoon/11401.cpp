// https://www.acmicpc.net/problem/11401
#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int n, k, res;
ll a = 1, b = 1;

ll fast_mult(ll x, ll pow) {
  ll cur = x;
  ll ret = 1;
  while (pow > 0) {
    if (pow % 2 == 1) {
      ret = (ret * cur) % MOD;
    }
    pow /= 2;
    cur = (cur * cur) % MOD;
  }
  return ret;
}

ll find_inverse(ll x) {
  return fast_mult(x, MOD - 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    a = (a * (n - i)) % MOD;
    b = (b * (k - i)) % MOD;
  }

  res = (int) (((ll) a * find_inverse(b)) % MOD);
  cout << res << '\n';
  return 0;
}