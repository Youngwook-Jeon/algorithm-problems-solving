// https://www.acmicpc.net/problem/2468
#include <iostream>
#include <algorithm>
using namespace std;

int n;
// a: 지역의 높이들
// b: 물에 잠기면 0, 아니면 1
// max_height: 지역의 높이중 최대값
int a[101][101], b[101][101], visited[101][101], temp, ans = 1, max_height;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int i, int j) {
  visited[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int next_x = j + dx[k];
    int next_y = i + dy[k];

    if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visited[next_y][next_x] && b[next_y][next_x]) {
      dfs(next_y, next_x);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      max_height = max(max_height, a[i][j]);
    }
  }

  for (int h = 1; h <= max_height; h++) {
    fill(&b[0][0], &b[0][0] + 101 * 101, 0);
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] > h) {
          b[i][j] = 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && b[i][j]) {
          dfs(i, j);
          temp++;
        }
      }
    }

    ans = max(ans, temp);
    temp = 0;
  }

  cout << ans << endl;
  return 0;
}