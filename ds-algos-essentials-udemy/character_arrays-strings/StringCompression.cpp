// 문자열 압축할 때 만들어지는 문자열의 길이 리턴
#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    // your code goes here
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i < chars.size(); i++) {
        if (chars[i - 1] == chars[i]) {
            cnt++;
        } else if (cnt == 1) {
            ans += 1;
        } else {
            ans += to_string(cnt).size() + 1;
            cnt = 1;
        }
    }
    if (cnt == 1) {
        ans += 1;
    } else {
        ans += to_string(cnt).size() + 1;
    }
    return ans;
}