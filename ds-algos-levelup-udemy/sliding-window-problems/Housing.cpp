// 땅의 크기들이 배열로 주어졌을 때, 연속적으로 붙어있는 땅을 사서 집을 지으려고 한다
// 이때 반드시 K 만큼의 땅을 사서 집을 짓는다고 할 때 살 수 있는 연속적인 위치를 리턴하기
#include <iostream>
using namespace std;

void housing(int *arr, int n, int k) {
  int i = 0, j = 0, cs = 0;

  while (j < n) {
    // expand to right
    cs += arr[j];
    j++;

    // remove elements from the left till cs > sum and i < j
    while (cs > k and i < j) {
      cs = cs - arr[i];
      i++;
    }

    if (cs == k) {
      cout << i << " - " << j - 1 << endl;
    }
  }
  return;
}

int main() {
  int plots[] = { 1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
  int n = sizeof(plots) / sizeof(int);
  int k = 8;

  housing(plots, n, k);
  return 0;
}