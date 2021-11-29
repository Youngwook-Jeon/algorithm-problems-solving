// 1부터 N까지 증가하는 순으로 원소를 가지는 벡터 리턴하기. 재귀로 풀기
#include <iostream>
#include <vector>
using namespace std;

void helper(int i, int n, vector<int> &v) {
    if (i > n) return;
    v.push_back(i);
    helper(i + 1, n, v);
}

vector<int> increasingNumbers(int N) {
    vector<int> v;
    helper(1, N, v);
    return v;
}

int main() {
	// your code goes here
    vector<int> v = increasingNumbers(5);
    for (auto i : v) {
        cout << i << " ";
    }
	return 0;
}

