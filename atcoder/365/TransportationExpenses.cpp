#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool check(vector<ll> &arr, int n, ll m, ll x) {
    ll bu = 0;
    for (int i = 0; i < n; i++) {
        bu += min(x, arr[i]);
    }

    return bu <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll m;
    cin >> n >> m;
    vector<ll> arr(n);
    ll sm = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sm += arr[i];
    }

    if (sm <= m) {
        cout << "infinite";
        return 0;
    }

    sort(arr.begin(), arr.end());

    ll lo = 1, hi = arr[n - 1];
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (check(arr, n, m, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << hi;
    return 0;
}