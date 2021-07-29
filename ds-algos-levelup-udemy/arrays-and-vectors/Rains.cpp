// 바 들의 높이들이 주어졌을 때 채워질 수 있는 최대 물의 양 구하기
#include <iostream>
#include <vector>
using namespace std;

int trapped_water(vector<int> heights) {
    int n = heights.size();
    if (n <= 2) {
        return 0;
    }

    // left max, right max 들을 저장할 두 벡터 선언하기
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += min(left[i], right[i]) - heights[i];
    }

    return answer;
}

int main() {
    vector<int> water = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << trapped_water(water) << endl;
    return 0;
}