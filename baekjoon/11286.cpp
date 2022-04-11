// https://www.acmicpc.net/problem/11286
// 절댓값으로 비교하는 힙 구현하기
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int n;

struct cmp {
  bool operator() (int a, int b) {
    int abs_a = abs(a);
    int abs_b = abs(b);
    if (abs_a != abs_b) return abs_a > abs_b;
    return a > b;
  }
};

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  priority_queue<int, vector<int>, cmp> pq;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a != 0) {
      pq.push(a);
    } else {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        int x = pq.top();
        pq.pop();
        cout << x << '\n';
      }
    }
  }
  return 0;
}