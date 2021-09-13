// n개의 서로 다른 책의 페이지 수들과 m명의 학생들이 있다
// 모든 학생들은 책 배열의 연속된 부분들을 할당받아 책을 읽는다
// 이때 학생들중 할당받은 책들의 페이지의 합이 가장 큰 경우를 val 이라고하자
// 그 val 값의 최소값을 구하는 것이 목표
#include <iostream>
#include <vector>
using namespace std;

bool canRead(vector<int> &books, int m, int n, int mid) {
    int current = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (books[i] > mid) return false;
        if (current + books[i] > mid) {
            cnt++;
            current = books[i];
            if (cnt > m) return false;
        } else {
            current += books[i];
        }
    }
    return true;
}


int minPages(vector<int> books, int m){
    int s = 0, e = 0;
    int ans = 0;
    int n = books.size();
    for (int i = 0; i < n; i++) {
        s = max(s, books[i]);
        e += books[i];
    }
    
    while (s <= e) {
        int mid = (s + e) / 2;
        if (canRead(books, m, n, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}