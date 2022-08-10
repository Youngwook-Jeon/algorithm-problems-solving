// https://www.acmicpc.net/problem/11505
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
int n, m, k, height, tree_size, trans_ind;

void make_mult_tree(vector<int> &tree) {
  int start = tree.size() - 2;
  while (start > 1) {
    tree[start / 2] = (int) ((((ll) tree[start]) * tree[start / 2]) % MOD);
    start--;
  }
}

int get_range_mult(vector<int> &tree, int s, int e) {
  ll ans = 1LL;
  while (s <= e) {
    if (s % 2 == 1) {
      ans = (ans * tree[s]) % MOD;
      s++;
    }

    if (e % 2 == 0) {
      ans = (ans * tree[e]) % MOD;
      e--;
    }
    s /= 2;
    e /= 2;
  }

  return (int) (ans % MOD);
}

void change(vector<int> &tree, int ind, int new_val) {
  tree[ind] = new_val;
  while (ind > 1) {
    ind = ind / 2;
    tree[ind] = (int) ((((ll) tree[ind * 2]) * tree[ind * 2 + 1]) % MOD);
  }
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

  vector<int> tree(tree_size + 1, 1);

  for (int i = trans_ind + 1; i <= trans_ind + n; i++) {
    cin >> tree[i];
  } 

  make_mult_tree(tree);

  for (int i = 0; i < m + k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      change(tree, trans_ind + b, c);
    } else if (a == 2) {
      int ans = get_range_mult(tree, trans_ind + b, trans_ind + c);
      cout << ans << "\n";
    }
  }

  return 0;
}