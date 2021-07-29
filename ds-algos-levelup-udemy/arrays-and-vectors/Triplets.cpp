// 배열과 어떤 수 S가 주어졌을 때, 배열의 서로다른 세 수를 더하여 S를 만들 수 있는 모든 경우의 쌍을 출력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> arr, int Sum) {
    vector<vector<int> > result;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i <= n - 3; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum == Sum) {
                result.push_back({ arr[i], arr[j], arr[k] });
                j++;
                k--;
            } else if (current_sum > Sum) {
                k--;
            } else {
                j++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr{1, 15, 9, 8, 7, 6, 5, 4, 3, 2 };
    int S = 18;
    auto result = triplets(arr, S);

    for (auto v : result) {
        for (auto num : v) {
            cout << num << ",";
        }
        cout << endl;
    }
    return 0;
}