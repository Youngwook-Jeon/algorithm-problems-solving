// 주어진 2차원 배열의 0이 존재하는 행과 같은 행, 그 열과 같은 열에 있는 모든 원소들을 0으로 만들기
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int> > makeZeroes(vector<vector<int> > arr){
    // your code goes here
    int n = arr.size();
    unordered_set<int> r_s, c_s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                r_s.insert(i);
                c_s.insert(j);
            }
        }
    }

    for (auto x : r_s) {
        for (int j = 0; j < n; j++) {
            arr[x][j] = 0;
        }
    }

    for (auto y : c_s) {
        for (int i = 0; i < n; i++) {
            arr[i][y] = 0;
        }
    }

    return arr;
}