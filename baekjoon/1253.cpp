// https://www.acmicpc.net/problem/1253
// GOOD 넘버(그 수가 배열의 다른 두 수의 합으로 표현가능)의 갯수를 출력하기
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
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v[i] = a;
  }

  sort(v.begin(), v.end());
  for (int target = 0; target < n; target++) {
    int st = 0, ed = n - 1;
    long long su;
    while (st < ed) {
      su = v[st] + v[ed];
      if (su < v[target]) {
        su -= v[st];
        st++;
      } else if (su > v[target]) {
        su -= v[ed];
        ed--;
      } else {
        // 현재 2개의 포인터가 타겟의 위치에 있는지 여부를 체크
        if (st != target && ed != target) {
          ans++;
          break;
        } else if (st == target) {
          st++;
        } else if (ed == target) {
          ed--;
        }
      }
    }
  }

  cout << ans;
  return 0;
}