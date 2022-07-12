// https://www.acmicpc.net/problem/1744
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int n, ans, ones, zeros;
priority_queue<int> plus_q;
priority_queue<int, vector<int>, greater<int> > minus_q;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    
    if (num > 1) {
      plus_q.push(num);
    } else if (num < 0) {
      minus_q.push(num);
    } else if (num == 1) {
      ones++;
    } else {
      zeros++;
    }
  }

  while (plus_q.size() > 1) {
    int num1 = plus_q.top();
    plus_q.pop();
    int num2 = plus_q.top();
    plus_q.pop();

    ans += num1 * num2;
  }

  while (minus_q.size() > 1) {
    int num1 = minus_q.top();
    minus_q.pop();
    int num2 = minus_q.top();
    minus_q.pop();

    ans += num1 * num2;
  }

  if (plus_q.size() == 1) {
    ans += plus_q.top();
  }

  if (minus_q.size() == 1 && zeros == 0) {
    ans += minus_q.top();
  }

  ans += ones;

  cout << ans << "\n";
  return 0;
}