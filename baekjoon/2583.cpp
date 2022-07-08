// https://www.acmicpc.net/problem/2583
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int a[100][100], visited[100][100], total;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int i, int j) {
  visited[i][j] = 1;
  int val = 1;
  
  for (int b = 0; b < 4; b++) {
    int next_y = i + dy[b];
    int next_x = j + dx[b];
    if (next_x < n && next_x >= 0 && next_y < m && next_y >=0 && !visited[next_y][next_x] && !a[next_y][next_x]) {
      val += dfs(next_y, next_x);
    }
  }

  return val;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> m >> n >> k;
  vector<int> ans;

  for (int i = 0; i < k; i++) {
    int l_x, l_y, r_x, r_y;
    cin >> l_x >> l_y >> r_x >> r_y;
    for (int c = l_x; c < r_x; c++) {
      for (int b = l_y; b < r_y; b++) {
        a[b][c] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && !a[i][j]) {
        ans.push_back(dfs(i, j));
        total++;
      }
    }
  }

  sort(ans.begin(), ans.end());

  cout << total << "\n";
  for (int num : ans) {
    cout << num << " ";
  }
  return 0;
}