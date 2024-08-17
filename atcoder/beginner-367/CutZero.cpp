#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string x;
    cin >> x;

    int i = x.size() - 1;
    while (i >= x.size() - 3) {
        if (x[i] != '0') {
            break;
        }
        i--;
    }

    string ans;
    if (i == x.size() - 4) {
        ans = x.substr(0, x.size() - 4);
    } else {
        ans = x.substr(0, i + 1);
    }

    cout << ans << '\n';
    return 0;
}