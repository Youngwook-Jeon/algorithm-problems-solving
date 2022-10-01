// https://www.acmicpc.net/problem/10830
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000

int n;
ll b;

vector<vector<int> > mat_mult(vector<vector<int> > &mat1, vector<vector<int> > &mat2) {
  vector<vector<int> > ret(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        ret[i][j] = (ret[i][j] + mat1[i][k] * mat2[k][j]) % MOD;
      }
    }
  }
  return ret;
}

vector<vector<int> > fast_mult(vector<vector<int> > &mat, ll pow) {
  vector<vector<int> > cur = mat;
  vector<vector<int> > ret(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    ret[i][i] = 1;
  }
  while (pow > 0) {
    if (pow % 2 == 1) {
      ret = mat_mult(ret, cur);
    }
    pow /= 2;
    cur = mat_mult(cur, cur);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> b;
  vector<vector<int> > mat(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  vector<vector<int> > ret = fast_mult(mat, b);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ret[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}