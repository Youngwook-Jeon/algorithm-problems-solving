// https://www.acmicpc.net/problem/10986
// i부터 j까지의 구간합이 m으로 나눠떨어지는 (i, j)의 경우의 수 출력하기
#include <iostream>
#include <vector>
using namespace std;

int n, m;
long long ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n >> m;
  vector<long long> s(n + 1, 0LL);
  vector<int> v(m, 0);
  for (int i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    s[i] = s[i - 1] + a;
  }

  for (int i = 1; i <= n; i++) {
    int r = (int) (s[i] % m);
    if (r == 0) {
      ans++;
    }
    v[r]++;
  }

  for (int i = 0; i < m; i++) {
    if (v[i] != 0) {
      ans += ((long long)v[i] * (v[i] - 1)) / 2;
    }
  }

  cout << ans;
  return 0;
}
