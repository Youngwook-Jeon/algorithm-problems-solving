// https://www.acmicpc.net/problem/1850
// Find the gcd of two given numbers consisted by only 1's.
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    ll num = gcd(a, b);
    while (num > 0) {
        cout << '1';
        num--;
    }
    return 0;
}