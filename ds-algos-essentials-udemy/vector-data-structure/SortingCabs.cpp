// (x, y) 좌표가 주어진 택시들의 배열이 주어졌을 때, 원점으로 부터 가까운 순으로 정렬하기
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second);
}

vector<pair<int,int> > sortCabs(vector<pair<int,int> > v){
    // your code  goes here
    sort(v.begin(), v.end(), compare);
    return v;
}