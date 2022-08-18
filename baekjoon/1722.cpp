// https://www.acmicpc.net/problem/1722
#include <iostream>
using namespace std;
typedef long long ll;

int n, q;
int ans[21];
ll k;
ll perm[21];
bool visited[21];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  perm[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    perm[i] = perm[i - 1] * i;
  }

  cin >> q;
  if (q == 1) {
    cin >> k;

    for (int i = 1; i <= n; i++) {
      int cnt = 1;
      for (int j = 1; j <= n; j++) {
        if (visited[j]) continue;

        if (k <= cnt * perm[n - i]) {
          k -= (cnt - 1) * perm[n - i];
          ans[i] = j;
          visited[j] = true;
          break;
        }
        cnt++;
      }
    }

    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
  } else {
    ll num = 1LL;

    for (int i = 1; i <= n; i++) {
      cin >> ans[i];
      ll cnt = 0LL;
      for (int j = 1; j < ans[i]; j++) {
        if (!visited[j]) {
          cnt++;
        }
      }
      num += (cnt * perm[n - i]);
      visited[ans[i]] = true;
    }

    cout << num << "\n";
  }

  return 0;
}