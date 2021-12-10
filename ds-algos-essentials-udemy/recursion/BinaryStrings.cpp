// n자리를 갖는 0과 1로 구성된 바이너리 문자열들을 순서대로 나열하기
// 단 연속된 1이 존재하는 바이너리 문자열은 제외함
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

void helper(string s, int n, int i) {
    if (i == n) {
        v.push_back(s);
        return;
    }
    string copied = s;
    copied.push_back('0');
    helper(copied, n, i + 1);
    
    if (i > 0 and s[i - 1] == '0') {
        s.push_back('1');
        helper(s, n, i + 1);
    } else if (i == 0) {
        s.push_back('1');
        helper(s, n, i + 1);
    }
    
}

vector<string> binaryStrings(int n){
    // do not modify any default function or parameter you can use helper function if needed
    v.clear();
    string s;
    helper(s, n, 0);
    return v;
}