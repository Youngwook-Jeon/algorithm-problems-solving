// https://www.acmicpc.net/problem/1715
// Find the minimum number of comparisons of given card decks
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int n, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    q.push(num);
  }

  while (!q.empty()) {
    int num1 = q.top();
    q.pop();
    if (q.empty()) {
      break;
    }
    int num2 = q.top();
    q.pop();
    int next = num1 + num2;
    ans += next;
    q.push(next);
  }

  cout << ans << "\n";
  return 0;
}