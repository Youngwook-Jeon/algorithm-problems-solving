// 한 문자열이 다른 문자열에서 등장하는 모든 케이스의 첫 인덱스 반환하기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> stringSearch(string big, string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int index = 0;
    while (index != -1) {
        index = big.find(small, index);
        if (index != -1) {
            result.push_back(index);
            index++;
        }
    }
    
    return result;
}
