// https://www.acmicpc.net/problem/9996
// 주어진 패턴에 맞는 문자열인지 아닌지를 체크하기
#include <iostream>
#include <vector>
using namespace std;

int n;
string p, s;
vector<string> v;

int main() {
    cin >> n;
    cin >> p;
    for (int i = 0; i < n; i++) {
        cin >> s;
        bool b = true;
        int ss = s.size(), ps = p.size();
        if (ss + 1 < ps) {
            b = false;
        }
        int k = 0;
        while (b and p.at(k) != '*') {
            k++;
        }
        if (b and ((p.substr(0, k) != s.substr(0, k)) or (p.substr(k + 1) != s.substr(ss - ps + k + 1))))
            b = false;
        if (b) v.push_back("DA");
        else v.push_back("NE");
    }

    for (string sv : v) {
        printf("%s\n", sv.c_str());
    }
    return 0;
}