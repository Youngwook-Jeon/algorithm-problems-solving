#include <iostream>
#include <vector>
using namespace std;

int n;

void solve(vector<int>& v, int k) {
  vector<int> temp(n);
  int cnt = 0;
  int d = 1;

  while (cnt < k) {
    vector<int> bucket(10);
    for (int i = 0; i < n; i++) {
      bucket[v[i] / d % 10]++;
    }

    for (int i = 0; i < 9; i++) {
      bucket[i + 1] += bucket[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      temp[bucket[v[i] / d % 10] - 1] = v[i];
      bucket[v[i] / d % 10]--;
    }

    for (int i = 0; i < n; i++) {
      v[i] = temp[i];
    }

    d *= 10;
    cnt++;
  }
}

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

  solve(v, 5);
  for (int i = 0; i < n; i++) {
    cout << v[i] << '\n';
  }
  return 0;
}