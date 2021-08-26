// k-윈도우가 주어진 배열을 훑고 지나갈 때, 각 윈도우의 최댓값들을 가지는 배열을 리턴
#include<vector>
#include <deque>
using namespace std;

// O(n) time complexity
vector<int> maxInWindow(vector<int> input,int k){
    deque<int> buffer; // 윈도우의 최대값이 될 수 있는 후보들을 저장할 버퍼, 최대값은 front에 있다
    vector<int> ans;
    
    for (int j = 0; j < input.size(); j++) {
        while (!buffer.empty() and input[j] >= input[buffer.back()]) buffer.pop_back();
        buffer.push_back(j);
        if (j >= k - 1) ans.push_back(input[buffer.front()]);
        if (buffer.front() <= j - k + 1) buffer.pop_front();
    }
    return ans;
}