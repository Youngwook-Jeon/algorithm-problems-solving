// https://www.acmicpc.net/problem/17298
// 수열의 각 원소의 NGE값(오른쪽에 있는 더 큰 원소중 가장 왼쪽에 있는 원소)구하기
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<int> v(n), res(n);
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }
  stk.push(0);
  for (int i = 1; i < n; i++) {
    while (!stk.empty() && v[stk.top()] < v[i]) {
      int tp = stk.top();
      res[tp] = v[i];
      stk.pop();
    }
    stk.push(i);
  }

  for (int i = 0; i < n; i++) {
    cout << (res[i] == 0 ? -1 : res[i]) << " ";
  }
  return 0;
}