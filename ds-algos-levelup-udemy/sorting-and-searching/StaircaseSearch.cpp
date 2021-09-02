// 로우별, 컬럼별로 각각 정렬된 배열이 주어졌을 때 찾고자 하는 값의 위치 인덱스를 반환
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> search(int m, int n, vector<vector<int> > v, int k) {
    int i = 0, j = n - 1;

    while (i < m and j >= 0) {
        if (v[i][j] == k) return {i, j};
        else if (v[i][j] > k) {
            j--;
        } else {
            i++;
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int> > v {{1, 4, 9}, {2, 5, 10}, {6, 7, 11}};
    pair<int, int> p = search(3, 3, v, 6);
    cout << p.first << " " << p.second << endl;
    return 0;
}