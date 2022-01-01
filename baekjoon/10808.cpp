// https://www.acmicpc.net/problem/10808
#include <iostream>
#include <string>
using namespace std;

string s;
int a[26];

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        a[s.at(i) - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}