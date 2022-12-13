// https://atcoder.jp/contests/abc081/tasks/abc081_b
#include <iostream>
#include <vector>
using namespace std;

int n, ans;
bool flag;

int main() {
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (true) {
        if (!flag) {
            for (int i = 0; i < n; i++) {
                if (v[i] % 2 == 1) {
                    flag = true;
                    break;
                }
                v[i] /= 2; 
            }
            if (!flag) ans++;
        } else {
            break;
        }
        
    }

    cout << ans << '\n';

    return 0;
}