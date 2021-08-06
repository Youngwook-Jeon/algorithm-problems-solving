// 주어진 배열을 k번 로테이션 시켰을 때 얻어지는 배열을 리턴하기
#include <vector>
using namespace std;

vector<int> kRotate(vector<int> a, int k){
    // your code  goes here
    int n = a.size();
    k = k % n;
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {
        int ind = (i - k < 0) ? (n + i - k) : (i - k);
        ans[i] = a[ind];
    }
    
    return ans;
}