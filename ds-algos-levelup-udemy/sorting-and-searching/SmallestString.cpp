// 주어진 배열안의 문자열을 연결했을 때 얻을 수 있는 문자열 중에 가장 사전순으로 작은 문자열 출력하기
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(string x, string y) {
    return x + y < y + x;
}

int main() {
    string arr[] = {"a", "ab", "aba"};
    int n = 3;
    sort(arr, arr + n, compare);

    for (auto s : arr) {
        cout << s;
    }
    return 0;
}