// https://www.acmicpc.net/problem/9252
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s1, s2;
vector<char> lcs;

void findLCS(int row, int col, vector<vector<int> > &D) {
  if (row == 0 || col == 0) return;

  if (s1[row - 1] == s2[col - 1]) {
    lcs.push_back(s1[row - 1]);
    findLCS(row - 1, col - 1, D);
  } else {
    if (D[row - 1][col] > D[row][col - 1]) {
      findLCS(row - 1, col, D);
    } else {
      findLCS(row, col - 1, D);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> s1 >> s2;
  int l1 = s1.size();
  int l2 = s2.size();

  vector<vector<int> > D(l1 + 1, vector<int>(l2 + 1));
  for (int i = 1; i <= l1; i++) {
    for (int j = 1; j <= l2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        D[i][j] = D[i - 1][j - 1] + 1;
      } else {
        D[i][j] = max(D[i - 1][j], D[i][j - 1]);
      }
    }
  }

  cout << D[l1][l2] << '\n';
  if (D[l1][l2] != 0) {
    findLCS(l1, l2, D);
    reverse(lcs.begin(), lcs.end());
    for (char c : lcs) {
      cout << c;
    }
  }
  return 0;
}