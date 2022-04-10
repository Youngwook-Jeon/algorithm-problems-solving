// https://www.acmicpc.net/problem/1874
// 1부터 n까지 오름차순으로 스택에서 작업(push, pop)하여 주어진 수열을 만들어낼수 있는지 확인하기
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int n;
bool res = true;
string s = "";

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<int> v(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }

  int num = 1;
  for (int i = 0; i < n; i++) {
    int cur = v[i];
    if (num <= cur) {
      while (num <= cur) {
        st.push(num++);
        s += "+\n";
      }
      st.pop();
      s += "-\n";
    } else {
      int x = st.top();
      if (x != cur) {
        res = false;
        cout << "NO";
        break;
      }
      st.pop();
      s += "-\n";
    }
  }

  if (res) cout << s;
  return 0;
}