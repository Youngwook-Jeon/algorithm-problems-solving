// 정수 배열이 입력될 때 가장 높은 산의 길이를 구하기
// 산은 인접한 정수들로 구성되며, 가장 높은 피크에 이르기까지 strictly increasing 하고 
// 그 이후부턴 strictly decreasing하는 정수들임
#include <iostream>
#include <vector>
using namespace std;

int highest_mountain(vector<int> a) {
    int n = a.size();
    int largest = 0;
    for (int i = 1; i <= n - 2; ) {
        // check a[i] is peak or not
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
            int cnt = 1;
            int j = i;
            while (j >= 1 and a[j] > a[j - 1]) {
                j--;
                cnt++;
            }
            while (i <= n - 2 and a[i] > a[i + 1]) {
                i++;
                cnt++;
            }
            largest = max(largest, cnt);
        } else {
            i++;
        }
    }

    return largest;
}

int main() {
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout << highest_mountain(arr);

    return 0;
}