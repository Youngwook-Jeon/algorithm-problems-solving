// https://www.acmicpc.net/problem/2343
#include <iostream>
#include <vector>
using namespace std;

int n, m, s, e;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    e += v[i];
    if (s < v[i]) {
      s = v[i];
    }
  }

  int begin = s, end = e;
  while (begin <= end) {
    int mid = (begin + end) / 2;
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] + sum > mid) {
        count++;
        sum = 0;
      }
      sum += v[i]; 
    }

    count++;

    if (count > m) {
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << begin << "\n";
  return 0;
}