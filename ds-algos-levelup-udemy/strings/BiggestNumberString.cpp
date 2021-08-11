// 정수 배열이 주어졌을 때 그 배열들의 원소를 이어 붙였을 때 만들수 있는 가장 큰 수 찾기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int n1, int n2) {
    return to_string(n1) + to_string(n2) < to_string(n2) + to_string(n1);
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    sort(numbers.begin(), numbers.end(), compare);
    string ans = "";
    for (int i = numbers.size() - 1; i >= 0; i--) {
        ans += to_string(numbers[i]);
    }
    return ans;
}