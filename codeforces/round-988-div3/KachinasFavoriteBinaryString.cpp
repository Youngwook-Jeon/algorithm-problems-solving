#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forEachTestCase long long numTestCase; cin >> numTestCase; while (numTestCase--)
#define newl '\n'

void use_file_input_output() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void solve() {
    int n;
    cin >> n;
    string ans = "0";
    int prev = 0;
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << ' ' << i << newl;
        cout.flush();

        int f;
        cin >> f;
        if (f == 0) {
            if (ans.back() == '0') {
                ans[ans.size() - 1] = '1';
            }
            ans.push_back('1');
            continue;
        }

        flag = true;

        if (prev == 0) {
            for (int j = i - 2; j > i - 2 - f; j--) {
                ans[j] = '0';
            }
            ans.push_back('1');
        } else if (prev < f) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
        prev = f;
    }

    if (!flag) {
        cout << "! IMPOSSIBLE" << newl;
    } else {
        cout << "! " + ans << newl;
    }
    cout.flush();
}

int main() {
    FASTIO
    forEachTestCase solve();
    return 0;
}
