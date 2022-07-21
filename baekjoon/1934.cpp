// Find the gcd of given two numbers.
#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> v;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int lcm = (a * b) / gcd(a, b);
        v.push_back(lcm);
    }

    for (int num : v) {
        cout << num << "\n";
    }
    return 0;
}