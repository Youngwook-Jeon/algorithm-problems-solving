// https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(b, a);
  }

  sort(v.begin(), v.end());

  int s = v[0].first;
  for (int i = 1; i < n; i++) {
    if (v[i].second >= s) {
      ans++;
      s = v[i].first;
    }
  }

  cout << ans << "\n";
  return 0;
}