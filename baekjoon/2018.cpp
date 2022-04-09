// https://www.acmicpc.net/problem/2018
// n이 연속된 자연수의 합으로 표현될 수 있는 경우의 수 출력하기
#include <iostream>
using namespace std;

int n, st = 1, ed = 1, su = 1, ans = 1;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;

  while (ed < n) {
    if (su > n) {
      su -= st;
      st++;
    } else if (su < n) {
      ed++;
      su += ed;
    } else {
      ed++;
      su += ed;
      ans++;
    }
  }
  cout << ans;
}