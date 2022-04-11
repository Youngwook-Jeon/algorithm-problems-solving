// https://www.acmicpc.net/problem/2164
// 특정 규칙을 가지고 n이하의 카드를 버릴 때, 남은 카드의 번호를 출력하기
#include <iostream>
#include <queue>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  queue<int> q;

  for (int i = 0; i < n; i++) {
    q.push(i + 1);
  }

  while (q.size() > 1) {
    q.pop();
    int i = q.front();
    q.push(i);
    q.pop();
  }

  printf("%d", q.front());
  return 0;
}