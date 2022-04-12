// https://www.acmicpc.net/problem/11399
// selection sort 사용하여 풀기
#include <iostream>
#include <vector>
using namespace std;

int n, ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<int> v(n);
  vector<int> su(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }

  for (int i = 1; i < n; i++) {
    int ind = i;
    int val = v[i];
    for (int j = i - 1; j >= 0; j--) {
      if (v[i] > v[j]) {
        ind = j + 1;
        break;
      }
      if (j == 0) {
        ind = 0;
      }
    }

    for (int j = i; j > ind; j--) {
      v[j] = v[j - 1];
    }
    v[ind] = val;
  }

  su[0] = v[0];
  for (int i = 0; i < n - 1; i++) {
    su[i + 1] = su[i] + v[i + 1];
  }
  for (int i = 0; i < n; i++) {
    ans += su[i];
  }
  
  cout << ans;
  return 0;
}