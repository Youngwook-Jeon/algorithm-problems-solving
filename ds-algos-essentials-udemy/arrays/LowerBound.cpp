#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> A,int Val) {
    // your code goes here
    int s = 0;
    int e = A.size() -1;
    
    while (s <= e){
        int mid = (s + e) / 2;
        if (A[mid] == Val) {
            return A[mid];
        }
        else if (A[mid] > Val) {
            e = mid -1;
        }
        else {
            s = mid +1;
        }
    }
    if (A[e] > Val) {
        return A[e-1];
    }
    else if (Val > A[e]) {
        return A[e];
    }
    else {
        return -1;
    }
}

int main() {
    vector<int> arr {-1, -1, 2, 3, 5};
    cout << lowerBound(arr, 4) << endl;
    cout << lowerBound(arr, 0) << endl;
    cout << lowerBound(arr, 3) << endl;
    return 0;
}