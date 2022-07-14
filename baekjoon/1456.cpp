// https://www.acmicpc.net/problem/1456
// Find the number of "almost prime" integers of a given range.
#include <iostream>
using namespace std;
typedef long long ll;
const int LENGTH = 10000001;

int ans;
ll a, b;
int is_prime[LENGTH];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> a >> b;
  for (int i = 2; i < LENGTH; i++) {
    is_prime[i] = 1;
  }

  for (int i = 2; i * i <= LENGTH - 1; i++) {
    for (int j = i + i; j <= LENGTH - 1; j += i) {
      if (is_prime[j] == 0) continue;

      is_prime[j] = 0;
    }
  }

  for (int i = 2; i < LENGTH; i++) {
    if (is_prime[i] == 0) continue;

    ll temp = (ll) i;
    while (temp <= b / (ll) i) {
      temp *= i;
      if (temp >= a) {
        ans++;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}