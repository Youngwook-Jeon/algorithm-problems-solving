// 문자열이 주어졌을 때, 그 문자열의 모든 서브시퀀스들을 길이순으로 정렬하되 길이가 같을 시 사전식 순서로 정렬하기
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void subsequence(string s, string o, vector<string> &v) {
    if (s.size() == 0) {
        v.push_back(o);
        return;
    }

    char ch = s[0];
    string reduced_input = s.substr(1);
    subsequence(reduced_input, o + ch, v);
    subsequence(reduced_input, o, v);
}

bool compare(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main() {
    string s;
    cin >> s;
    vector<string> v;
    string output = "";
    subsequence(s, output, v);

    sort(v.begin(), v.end(), compare);

    for (auto s : v) {
        cout << s << ", ";
    }
    return 0;
}