// https://www.acmicpc.net/problem/1940
// 주어진 배열의 두 원소의 합을 더하여 m이 되는 경우의 수 출력하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  cin >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }

  sort(v.begin(), v.end());
  int start = 0, end = n - 1;
  while (start < end) {
    int su = v[start] + v[end];
    if (su < m) {
      su -= v[start];
      start++;
    } else if (su > m) {
      su -= v[end];
      end--;
    } else {
      su -= v[end];
      end--;
      ans++;
    }
  }

  cout << ans;
}