// 정수 배열이 주어졌을 때, 오름차순으로 제대로 정렬하려면 최소 몇번의 스왑이 필요한지 구하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_min_swaps(vector<int> arr) {
    int n = arr.size();
    int ans = 0;
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++) {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap, ap + n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        int old_pos = ap[i].second;
        if (visited[i] == true or old_pos == i) {
            continue;
        }

        int node = i;
        int cycle = 0;
        while (!visited[node]) {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main() {
    vector<int> arr{5, 4, 3, 2, 1};
    cout << count_min_swaps(arr) << endl;
    return 0;
}