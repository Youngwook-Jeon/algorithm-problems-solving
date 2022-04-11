#include <iostream>
#include <vector>
using namespace std;

// 배열 A의 부분합을 빠르게 구할수있음 (O(logn))
struct FenwickTree {
  vector<int> tree;
  FenwickTree(int n):
    tree(n + 1) {}

  // A[0...pos]의 부분합
  int sum(int pos) {
    ++pos;
    int ret = 0;
    while (pos > 0) {
      ret += tree[pos];
      // 최종비트를 지워서 다음 구간을 구함
      pos &= (pos - 1);
    }
    return ret;
  }

  // A[pos]에 val을 더함
  void add(int pos, int val) {
    ++pos;
    while (pos < tree.size()) {
      tree[pos] += val;
      pos += (pos & -pos);
    }
  }
};