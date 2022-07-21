// Solve an equation of the form of Ax + By = C
#include <iostream>
using namespace std;

int a, b, c;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pair<int, int> solve(int a, int b) {
    if (b == 0) {
        return make_pair(1, 0);
    }
    int q = a / b;
    pair<int, int> p = solve(b, a % b);
    return make_pair(p.second, p.first - p.second * q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    if (c == 0) {
        cout << 0 << " " << 0;
        return 0;
    }

    int g = gcd(a, b);
    if (c % g != 0) {
        cout << -1;
        return 0;
    }

    int k = c / g;
    pair<int, int> p = solve(a, b);
    cout << p.first * k << " " << p.second * k << endl;
    return 0;
}