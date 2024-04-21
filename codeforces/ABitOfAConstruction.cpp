#include <iostream>
using namespace std;

void solve(int n, int k) {
    if (n == 1) {
        cout << k << '\n';
        return;
    }
    int x = 1;
    while (((x << 1) | 1) <= k) x = (x << 1) | 1;
    cout << x << ' ' << k - x;
    for (int i = 3; i <= n; i++) {
        cout << " 0";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}