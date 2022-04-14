// https://www.acmicpc.net/problem/1517
// 버블정렬을 진행하면서 발생하는 swap의 총 합을 구하기
#include <iostream>
#include <vector>
using namespace std;

int n;
long long res;

void merge_sort(vector<int>& v, vector<int>& temp, int st, int ed) {
  if (st >= ed) return;

  int mid = (st + ed) / 2;
  merge_sort(v, temp, st, mid);
  merge_sort(v, temp, mid + 1, ed);

  for (int i = st; i <= ed; i++) {
    temp[i] = v[i];
  }

  int ind1 = st, ind2 = mid + 1;
  int pos = st;
  while (ind1 <= mid && ind2 <= ed) {
    if (temp[ind1] > temp[ind2]) {
      res += ind2 - pos;
      v[pos++] = temp[ind2];
      ind2++;
    } else {
      v[pos++] = temp[ind1];
      ind1++;
    }
  }

  while (ind1 <= mid) {
    v[pos++] = temp[ind1];
    ind1++;
  }

  while (ind2 <= ed) {
    v[pos++] = temp[ind2];
    ind2++;
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<int> v(n), temp(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }

  merge_sort(v, temp, 0, n - 1);
  cout << res;
  return 0;
}