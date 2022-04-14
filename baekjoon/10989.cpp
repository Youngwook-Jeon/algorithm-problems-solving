// https://www.acmicpc.net/problem/10989
// 입력값이 작은 값들인 경우 정렬하기
#include <iostream>
using namespace std;

int n;
int arr[10001];

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[a]++;
  }

  for (int i = 1; i < 10001; i++) {
    for (int j = 0; j < arr[i]; j++) {
      cout << i << '\n';
    }
  }
  return 0;
}