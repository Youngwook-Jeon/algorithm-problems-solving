// https://www.acmicpc.net/problem/2042
// Segment tree - range queries
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, k, height, tree_size, trans_ind;

void make_sum_tree(vector<ll> &tree) {
  int start = tree.size() - 2;
  
  while (start != 1) {
    tree[start / 2] += tree[start];
    start--;
  }
}

void change(vector<ll> &tree, int ind, ll val) {
  ll diff = val - tree[ind];
  while (ind > 0) {
    tree[ind] = tree[ind] + diff;
    ind /= 2;
  }
}

ll get_range_sum(vector<ll> &tree, int s, int e) {
  ll ans = 0LL;
  while (s <= e) {
    if (s % 2 == 1) {
      ans += tree[s];
      s++;
    }
    if (e % 2 == 0) {
      ans += tree[e];
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

  cin >> n >> m >> k;

  int temp = n;
  while (temp != 0) {
    temp /= 2;
    height++;
  }

  tree_size = (int) pow(2, height + 1);
  trans_ind = tree_size / 2 - 1;
  vector<ll> tree(tree_size + 1);

  for (int i = trans_ind + 1; i <= trans_ind + n; i++) {
    cin >> tree[i];
  }

  make_sum_tree(tree);

  for (int i = 0; i < m + k; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    if (a == 1) {
      change(tree, trans_ind + b, c);
    } else if (a == 2) {
      ll res = get_range_sum(tree, trans_ind + b, trans_ind + (int) c);
      cout << res << "\n";
    }
  }
  return 0;
}