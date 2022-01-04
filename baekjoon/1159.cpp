// https://www.acmicpc.net/problem/1159
// 성의 첫글자가 같은 사람이 5명 이상인 경우들을 출력
#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;
int arr[26];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr[s.at(0) - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] >= 5) {
            m++;
            printf("%c", (char)('a' + i));
        }
    }

    if (m == 0) printf("%s", "PREDAJA");
    return 0;
}