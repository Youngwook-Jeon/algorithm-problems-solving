#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    while (true) {
        ans++;
        sort(v.begin(), v.end(), greater<int>());
        v[0]--;
        v[1]--;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] <= 0) cnt++;
        }
        if (cnt >= n - 1) break;
    }

    cout << ans << '\n';
    return 0;
}