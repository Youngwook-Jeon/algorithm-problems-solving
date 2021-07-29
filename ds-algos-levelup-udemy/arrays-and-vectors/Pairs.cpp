// 배열과 어떤 수 S가 입력받았을 때 배열의 수로 만들어진 페어들 중 더해서 S가 되는 페어를 출력
// 반드시 합이 S가 되는 페어가 하나만 있다고 가정
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int Sum) {
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        int x = Sum - arr[i];
        // An iterator to the element, if the specified value is found, 
        // or unordered_set::end if it is not found in the container.
        // find() method's Time-complexity =>
        // Average case: constant.
        // Worst case: linear in container size.
        if (s.find(x) != s.end()) { 
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
    return {};
}

int main() {
    vector<int> arr{10, 5, 2, 3, -6, 9, 1};
    int S = 4;
    auto p = pairSum(arr, S);
    if (p.size() == 0) {
        cout << "No such pair";
    } else {
        cout << p[0] << "," << p[1] << endl;
    }
    return 0;
}