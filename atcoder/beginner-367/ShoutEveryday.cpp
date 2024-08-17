#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c) {
    if (b < c) {
        if (a > b && a < c) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    } else {
        if (a > b || a < c) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}