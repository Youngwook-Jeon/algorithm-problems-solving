// https://www.acmicpc.net/problem/14003
#include <iostream>
using namespace std;

const int MAX_VAL = 1000001;
int n, ind, max_len = 1;
int helper[MAX_VAL];
int A[MAX_VAL];
int ans[MAX_VAL];
int D[MAX_VAL];

int bsearch(int s, int e, int val) {
  while (s < e) {
    int mid = (s + e) / 2;
    if (helper[mid] < val) {
      s = mid + 1;
    } else {
      e = mid;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  helper[max_len] = A[1];
  D[1] = 1;

  for (int i = 2; i <= n; i++) {
    if (helper[max_len] < A[i]) {
      helper[++max_len] = A[i];
      D[i] = max_len;
    } else {
      ind = bsearch(1, max_len, A[i]);
      helper[ind] = A[i];
      D[i] = ind;
    }
  }

  ind = max_len;
  int prev_val = helper[max_len] + 1;
  for (int i = n; i >= 1; i--) {
    if (D[i] == ind && A[i] < prev_val) {
      ans[ind] = A[i];
      prev_val = A[i];
      ind--;
    }
  }

  cout << max_len << '\n';
  for (int i = 1; i <= max_len; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}