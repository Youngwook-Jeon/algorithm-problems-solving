// 1 x m의 길이를 가지는 n개의 타일이 주어졌을 때, 이 타일을 수평 혹은 수직으로 채워서 n x m 보드를 메꾸는 경우의 가짓수 리턴
#include <iostream>
using namespace std;

int tillingProblem(int n, int m) {
    if (n < m) return 1;
    return tillingProblem(n - 1, m) + tillingProblem(n - m, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << "answer: " << tillingProblem(n, m) << endl;
    return 0;
}