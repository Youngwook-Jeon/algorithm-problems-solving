#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INT_MAXIMUM = numeric_limits<int>::max();

struct RMQ {
  int n; // 배열 길이
  vector<int> rangeMin;
  RMQ(const vector<int>& array) {
    n = array.size();
    rangeMin.resize(4 * n);
    init(array, 0, n - 1, 1);
  }

  // node 노드가 array[left...right] 배열을 표현할 때 그 노드를 루트로 하는 서브트리를 초기화하고 이 구간의 최소치 반환
  int init(const vector<int>& array, int left, int right, int node) {
    if (left == right) {
      return rangeMin[node] = array[left];
    }
    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, 2 * node);
    int rightMin = init(array, mid + 1, right, 2 * node + 1);
    return rangeMin[node] = min(leftMin, rightMin);
  }

  // node가 표현하는 범위가 주어졌을 때 array[left...right]와의 교집합의 최소치를 구함
  int query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if (right < nodeLeft || left > nodeRight) return INT_MAXIMUM;
    if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query(left, right, 2 * node, nodeLeft, mid), 
      query(left, right, 2 * node + 1, mid + 1, nodeRight));
  }

  int query(int left, int right) {
    return query(left, right, 1, 0, n - 1);
  }

  // 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환
  int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
    if (index < nodeLeft || index > nodeRight) return rangeMin[node];
    if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
    int mid = (nodeLeft + nodeRight) / 2;
    return rangeMin[node] = min(update(index, newValue, 2 * node, nodeLeft, mid), 
      update(index, newValue, 2 * node + 1, mid + 1, nodeRight));
  }

  int update(int index, int newValue) {
    return update(index, newValue, 1, 0, n - 1);
  }
};