// https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>
using namespace std;

int n, k, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    if (v[i] <= k) {
      int num = k / v[i];
      ans += num;
      k %= v[i];
    }
  }

  cout << ans << "\n";
  
  return 0;
}