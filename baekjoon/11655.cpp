// https://www.acmicpc.net/problem/11655
// 알파벳을 13글자 밀어서 만들어지는 암호문을 출력하기
#include <iostream>
#include <string>
using namespace std;

string s, t;
int main() {
    getline(cin, s);
    for (char c : s) {
        if (c >= 'A' and c <= 'Z') {
            t += (c + 13 - 'A') % 26 + 'A';
        } else if (c >= 'a' and c <= 'z') {
            t += (c + 13 - 'a') % 26 + 'a';
        } else {
            t += c;
        }
    }
    printf("%s", t.c_str());
    return 0;
}