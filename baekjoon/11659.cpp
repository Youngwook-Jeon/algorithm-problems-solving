// https://www.acmicpc.net/problem/11659
// 구간합구하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100000];
long long su[100001];
int n, m, k, st, ed;

int main() {
  cin >> n >> m;
  vector<long long> v(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> k;
    arr[i] = k;
    su[i + 1] = arr[i] + su[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> st >> ed;
    v[i] = su[ed] - su[st - 1];
  }

  for (int i = 0; i < m; i++) {
    printf("%lld\n", v[i]);
  }
  return 0;
}
