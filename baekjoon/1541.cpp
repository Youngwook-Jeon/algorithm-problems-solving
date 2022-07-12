// https://www.acmicpc.net/problem/1541
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int ans;

vector<string> split(string s, string separator) {
  vector<string> ret;
  int prev = 0;
  int cur = s.find(separator);
  while (cur != string::npos) {
    string substr = s.substr(prev, cur - prev);
    ret.push_back(substr);
    prev = cur + 1;
    cur = s.find(separator, prev);
  }
  ret.push_back(s.substr(prev));

  return ret;
}

int make_sum(string s) {
  int ret = 0;
  vector<string> v = split(s, "+");
  for (string sub : v) {
    ret += stoi(sub);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  getline(cin, s);

  vector<string> splitted = split(s, "-");

  ans = make_sum(splitted[0]);
  for (int i = 1; i < splitted.size(); i++) {
    ans -= make_sum(splitted[i]);
  }

  cout << ans << "\n";

  return 0;
}