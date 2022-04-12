// https://www.acmicpc.net/problem/2750
// 버블소트로 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }

  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 1; j < n - i; j++) {
      if (v[j - 1] > v[j]) {
        swap(v[j - 1], v[j]);
        flag = false;
      }
    }
    if (flag) break;
  }

  for (int i = 0; i < n; i++) {
    cout << v[i] << '\n';
  }
  return 0;
}