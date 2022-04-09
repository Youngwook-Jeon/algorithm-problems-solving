// https://www.acmicpc.net/problem/11003
// k-윈도우가 배열을 훑고 지날때 각 윈도우의 최솟값들을 출력하기
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n >> k;
  vector<long long> v(n);
  deque<long long> buffer; //윈도우의 최솟값이 될 후보들을 가지는 덱. front에 최솟값이 옴
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    v[i] = a;
  }

  for (int i = 0; i < n; i++) {
    while (!buffer.empty() && v[i] <= v[buffer.back()]) buffer.pop_back();
    buffer.push_back(i);
    cout << v[buffer.front()] << " ";
    if (buffer.front() <= i - k + 1) buffer.pop_front();
  }
  return 0;
}