// https://www.acmicpc.net/problem/2749
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
const int MOD = 1000000;

vector<vector<int> > mat = {{ 1, 1 }, { 1, 0 }};
vector<vector<int> > res = {{ 1, 0 }, { 0, 1 }};

vector<vector<int> > mat_mul(vector<vector<int> > &mat1 , vector<vector<int> > &mat2) {
  vector<vector<int> > ret(2, vector<int>(2, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ret[i][j] = (int) ((ret[i][j] + (ll)mat1[i][k] * mat2[k][j]) % MOD);
      }
    }
  }
  return ret;
} 

// Compute: mat ^ (n - 1)
void fast_mult() {
  ll cur = n - 1;
  vector<vector<int> > tmp = {{ 1, 1 }, { 1, 0 }};
  while (cur > 0) {
    if (cur % 2 == 1) {
      res = mat_mul(res, tmp);
    }
    tmp = mat_mul(tmp, tmp);
    cur /= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  fast_mult();
  cout << res[0][0] << '\n';
  return 0;
}