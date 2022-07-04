// https://www.acmicpc.net/problem/1629
// Fast multiplication
#include <iostream>
#include <bitset>
using namespace std;

int a, b, c, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> a >> b >> c;
  bitset<32> bs(b);
  string s = bs.to_string();
  if (a == 0) {
    cout << 0 << endl;
    return 0;
  }

  ans = 1;

  for (int i = 31; i >= 0; i--) {
    if (s.at(i) != '0') {
      ans = (int) (((long long) ans ) * a % c);
    }
    a = (int) (((long long) a ) * a % c);
  }

  cout << ans << endl;

  return 0;
}