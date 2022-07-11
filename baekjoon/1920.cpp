// https://www.acmicpc.net/problem/1920
// Binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  cin >> m;
  for (int i = 0; i < m; i++) {
    int target;
    int ans = 0;
    cin >> target;

    int begin = 0, end = n - 1;
    while (begin <= end) {
      int mid = (begin + end) / 2;
      if (v[mid] < target) {
        begin = mid + 1;
      } else if (v[mid] > target) {
        end = mid - 1;
      } else {
        ans = 1;
        break;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}