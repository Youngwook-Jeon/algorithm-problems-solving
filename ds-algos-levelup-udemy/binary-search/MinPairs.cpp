// 두 정수 배열이 주어졌을 때 각 배열에서 하나씩 뽑아 페어를 만든다고 하자
// 이때 페어의 두 수의 차의 절댓값이 최소가 되는 경우를 찾기
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2) {
    sort(a2.begin(), a2.end());
    int p1, p2;
    int diff = INT_MAX;

    for (int x : a1) {
        // x보다 같거나 큰 원소가 몇번째에서 최초로 등장하는지 계산하기
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();

        if (lb >= 1 and x - a2[lb - 1] < diff) {
            diff = x - a2[lb - 1];
            p1 = x;
            p2 = a2[lb - 1];
        }
        if (lb != a2.size() and a2[lb] - x < diff) {
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }
    }
    cout << "Min Pair " << p1 << " and " << p2 << endl;
    return;
}

int main() {
    vector<int> a1 = {-1, 5, 10, 20, 3};
    vector<int> a2 = {26, 134, 135, 15, 17};
    min_pair(a1, a2);
    return 0;
}