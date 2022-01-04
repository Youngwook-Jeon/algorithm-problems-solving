// https://www.acmicpc.net/problem/10988
// 팰린드롬 인지 여부를 확인하기
#include <iostream>
#include <string>
using namespace std;

string s;
int a = 1;

// reverse 함수 사용하는 다른 방법
void sol() {
    string s2, temp;
    cin >> s2;
    temp = s2;
    reverse(temp.begin(), temp.end());
    if (temp == s) cout << 1 << "\n";
    else cout << 0 << "\n";
}

int main() {
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n/2; i++) {
        if (s.at(i) != s.at(n - i - 1)) {
            a = 0;
            break;
        }
    }

    printf("%d", a);
    return 0;
}