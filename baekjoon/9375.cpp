// https://www.acmicpc.net/problem/9375
// 옷을 입을 수 있는 경우의 가짓수 구하기
#include <iostream>
#include <map>
#include <string>
using namespace std;

int t, n;
string s1, s2;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> t;

  while (t > 0) {
    long long ans = 1;
    map<string, int> mp;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
      cin >> s1 >> s2;
      mp[s2]++;
    }

    for (auto p : mp) {
      ans *= (long long) (p.second + 1);
    }

    // Eliminate the case that he wears nothing!
    ans -= 1;
    cout << ans << "\n";
    t--;
  }
  return 0;
}