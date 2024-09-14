#include <bits/stdc++.h>
using namespace std;

int main() {
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    vector<vector<int>> v(3);
    if (c1 == '<') {
        v[0].push_back(1);
    } else {
        v[1].push_back(0);
    }

    if (c2 == '<') {
        v[0].push_back(2);
    } else {
        v[2].push_back(0);
    }

    if (c3 == '<') {
        v[1].push_back(2);
    } else {
        v[2].push_back(1);
    }

    if (v[0].size() == 1) {
        cout << "A" << '\n';
    } else if (v[1].size() == 1) {
        cout << "B" << '\n';
    } else {
        cout << "C" << '\n';
    }
    return 0;
}