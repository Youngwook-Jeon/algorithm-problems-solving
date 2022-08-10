// https://www.acmicpc.net/problem/10868
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, height, tree_size, trans_ind;

void make_min_tree(vector<int> &tree) {
  int start = tree.size() - 2;
  while (start > 1) {
    tree[start / 2] = min(tree[start / 2], tree[start]);
    start--;
  }
}

int get_range_min(vector<int> &tree, int s, int e) {
  int ans = INT_MAX;
  while (s <= e) {
    if (s % 2 == 1) {
      ans = min(ans, tree[s]);
      s++;
    }

    if (e % 2 == 0) {
      ans = min(ans, tree[e]);
      e--;
    }
    s /= 2;
    e /= 2;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;

  int temp = n;
  while (temp != 0) {
    temp /= 2;
    height++;
  }

  tree_size = (int) pow(2, height + 1);
  trans_ind = tree_size / 2 - 1;

  vector<int> tree(tree_size + 1, INT_MAX);

  for (int i = trans_ind + 1; i <= trans_ind + n; i++) {
    cin >> tree[i];
  }

  make_min_tree(tree);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    cout << get_range_min(tree, a + trans_ind, b + trans_ind) << "\n";
  }
  return 0;
}