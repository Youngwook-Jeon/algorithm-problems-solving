// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> b;
int a[9];
int sum = 0;
int i, j;

// next_permutation 함수를 사용한 또다른 방법
int another_sol() {
    for (int k = 0; k < 9; k++) {
        cin >> a[i];
    }

    sort(a, a + 9);
    do {
        int res = 0;
        for (int k = 0; k < 7; k++) {
            res += a[k];
        }
        if (res == 100) break;
    } while (next_permutation(a, a + 9));

    for(int i = 0; i < 7; i++) cout << a[i] << "\n"; 
    return 0;
}

void helper(int a[]) {
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 9; j++) {
            if (sum - a[i] - a[j] == 100) return;
        }
    }
}

int main() {
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    helper(a);
    
    for (int k = 0; k < 9; k++) {
        if (k != i and k != j) {
            b.push_back(a[k]);
        }
    }
    sort(b.begin(), b.end());
    for (int k = 0; k < b.size(); k++) {
        cout << b[k] << "\n";
    }

    return 0;
}