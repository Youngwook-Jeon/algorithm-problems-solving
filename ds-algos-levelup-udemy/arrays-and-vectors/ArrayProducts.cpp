// 배열이 주어졌을 때 새로운 배열을 만드는데, 각 인덱스의 원소는 원래 배열에서 해당 인덱스의 원소만 제외한 모든 원소의 곱이다
// 단, 나눗셈을 사용하면 안됌!
#include <iostream>
#include <vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n, 1);
    
    //update the output array and return
    //complete the code
    vector<int> prefix(n, arr[0]);
    vector<int> suffix(n, arr[n - 1]);
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * arr[i];
        suffix[n - i - 1] = suffix[n - i] * arr[n - i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            output[i] = suffix[i + 1];
        } else if (i == n - 1) {
            output[i] = prefix[i - 1];
        } else {
            output[i] = prefix[i - 1] * suffix[i + 1];
        }
    }
    
    return output;
}