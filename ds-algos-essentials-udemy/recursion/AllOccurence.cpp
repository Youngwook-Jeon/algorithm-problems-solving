#include <vector>
#include <iostream>
using namespace std;

vector<int> ans;

void helper(int k, vector<int> v, int start, int end) {
    if (start > end) return;
    if (v[start] == k) ans.push_back(start);
    helper(k, v, start + 1, end);
}

vector<int> findAllOccurences(int k, vector<int> v){
    int start = 0, end = v.size() - 1;
    ans.clear();
    helper(k, v, start, end);
    return ans;
}
