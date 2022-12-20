// https://atcoder.jp/contests/abc045/tasks/arc061_a
#include <iostream>
using namespace std;
typedef long long ll;

string s;
ll ans;

int main() {
    cin >> s;
    int n = s.size();
    for (int bit = 0; bit < (1 << (n - 1)); bit++) {
        ll temp = 0;
        for (int i = 0; i < n - 1; i++) {
            temp *= 10;
            temp += s[i] - '0';
            if (bit & (1 << i)) {
                ans += temp;
                temp = 0;
            }
        }

        temp *= 10;
        temp += s[n - 1] - '0';
        ans += temp;
    }

    cout << ans << '\n';
    return 0;
}