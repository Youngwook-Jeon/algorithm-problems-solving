// 주어진 두 문자열이 퍼뮤테이션 관계에 있는지 체크하기
#include <iostream>
#include <string>
#include <map>
using namespace std;
 
bool arePermutation(string A, string B)
{
    // your code goes here
    if (A.size() != B.size()) return false;
    int n = A.size();
    map<char, int> m;
    
    for (char c : A) {
        if (m.find(c) != m.end()) {
            m[c] += 1;
        } else {
            m[c] = 1;
        }
    }
    
    for (char c : B) {
        if (m.find(c) == m.end() or m[c] <= 0) {
            return false;
        }
        m[c]--;
    }
    return true;
}