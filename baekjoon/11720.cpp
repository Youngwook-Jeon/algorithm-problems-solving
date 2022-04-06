// https://www.acmicpc.net/problem/11720
// 주어진 수열의 합을 출력하기
#include <iostream>
using namespace std;

int n, m, ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%1d", &m);
    ans += m;
  }

  printf("%d", ans);
}