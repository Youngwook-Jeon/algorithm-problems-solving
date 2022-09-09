// https://www.acmicpc.net/problem/11049
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct Mat {
  int row;
  int col;
};

int solve(int s, int e, vector<Mat> &matrices, vector<vector<int> > &D) {
  int ans = INT_MAX;
  if (D[s][e] != -1) {
    return D[s][e];
  }
  if (s == e) return 0;
  if (s + 1 == e) {
    return matrices[s].row * matrices[s].col * matrices[e].col;
  }

  for (int i = s; i < e; i++) {
    ans = min(ans, matrices[s].row * matrices[i].col * matrices[e].col + 
      solve(s, i, matrices, D) + solve(i + 1, e, matrices, D));
  }
  return D[s][e] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  vector<Mat> matrices(n + 1);
  // D[i][j] := the minimum number of operations of multiplication of matrices from ith to jth
  vector<vector<int> > D(n + 1, vector<int>(n + 1, -1)); 
  for (int i = 1; i <= n; i++) {
    int r, c;
    cin >> r >> c;
    matrices[i] = {r, c};
  }

  cout << solve(1, n, matrices, D) << '\n';
  return 0;
}