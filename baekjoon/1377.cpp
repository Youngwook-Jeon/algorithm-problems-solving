// https://www.acmicpc.net/problem/1377
// 버블 소트가 멈추는 경우(이미 정렬된 경우) 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());
  ans = -1;
  for (int i = 0; i < n; i++) {
    if (ans < v[i].second - i) {
      ans = v[i].second - i;
    }
  }
  ans += 1;
  cout << ans;
  return 0;
}