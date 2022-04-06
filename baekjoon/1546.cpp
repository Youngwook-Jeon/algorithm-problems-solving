// https://www.acmicpc.net/problem/1546
// 주어진 방법으로 새로운 평균구하기
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, su;
int mx = -1;
double ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    mx = max(mx, m);
    su += m;
  }
  ans = ((double) (su * 100)) / mx / n;
  printf("%f", ans);
  return 0;
}
