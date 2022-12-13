// https://atcoder.jp/contests/abc051/tasks/abc051_b
#include <iostream>
using namespace std;

int k, s, ans;

int main() {
    cin >> k >> s;

    for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
            if (x + y >= s - k && x + y <= s) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}