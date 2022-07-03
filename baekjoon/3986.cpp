// https://www.acmicpc.net/problem/3986
// Determine whether the given string is a "Good Pair".
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  while (n > 0) {
    stack<char> s;
    string str = "";
    cin >> str;

    for (char c : str) {
      if (s.size() != 0 && s.top() == c) {
        s.pop();
      } else {
        s.push(c);
      }
    }

    if (s.size() == 0) ans++;
    n--;
  }

  cout << ans << endl;
  
  return 0;
}
