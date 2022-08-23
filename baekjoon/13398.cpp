// https://www.acmicpc.net/problem/13398
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int arr[100000];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ans = arr[0];

  vector<int> left_sum(n);
  vector<int> right_sum(n);

  left_sum[0] = arr[0];
  right_sum[n - 1] = arr[n - 1];

  for (int i = 1; i < n; i++) {
    left_sum[i] = max(arr[i] + left_sum[i - 1], arr[i]);
    right_sum[n - i - 1] = max(arr[n - i - 1] + right_sum[n - i], arr[n - i - 1]);
    ans = max(left_sum[i], ans);
  }

  for (int i = 1; i < n - 1; i++) {
    int sum_except_i = left_sum[i - 1] + right_sum[i + 1];
    ans = max(sum_except_i, ans);
  }

  cout << ans << '\n';
  return 0;
}