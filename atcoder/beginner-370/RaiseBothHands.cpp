#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool l, r;
    cin >> l >> r;
    if ((l && r) || (!l && !r)) {
        cout << "Invalid" << '\n';
    } else if (l) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}