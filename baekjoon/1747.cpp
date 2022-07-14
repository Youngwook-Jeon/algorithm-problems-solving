// https://www.acmicpc.net/problem/1747
#include <iostream>
#include <string>
using namespace std;

int n, ans;

bool isPrime(int num) {
  if (num <= 1) return false;
  bool ret = true;

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      ret = false;
      break;
    }
  }

  return ret;
}

bool isPalindrome(int num) {
  bool ret = true;
  string str = to_string(num);

  int s = 0, e = str.size() - 1;
  while (s <= e) {
    if (str.at(s) != str.at(e)) {
      ret = false;
      break;
    }
    s++;
    e--;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  ans = n;

  while (true) {
    if (isPrime(ans) && isPalindrome(ans)) break;

    ans++;
  }

  cout << ans << "\n";
  return 0;
}