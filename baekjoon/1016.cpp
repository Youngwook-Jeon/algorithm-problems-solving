// https://www.acmicpc.net/problem/1016
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll mn, mx;
int ans;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> mn >> mx;
  vector<bool> v((int) (mx - mn + 1));

  for (ll i = 2; i * i <= mx; i++) {
    ll pow = i * i;
    ll s = mn / pow;
    if (mn % pow != 0) {
      s++;
    }

    for (ll j = s; j * pow <= mx; j++) {
      v[(int) (j * pow - mn)] = true;
    }
  }

  for (bool elm : v) {
    if (!elm) ans++;
  }

  cout << ans << "\n";

  return 0;
}