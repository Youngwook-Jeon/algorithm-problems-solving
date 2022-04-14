#include <iostream>
#include <vector>
using namespace std;

int t, m, n, k;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int j, int i) {
  visited[j][i] = true;
  for (int a = 0; a < 4; a++) {
    int nx = i + dx[a];
    int ny = j + dy[a];
    if (nx >= 0 && nx < m && ny >= 0 && ny < n && mat[ny][nx] == 1 && !visited[ny][nx]) {
      dfs(mat, visited, ny, nx);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> t;
  while (t > 0) {
    cin >> m >> n >> k;
    vector<vector<int> > mat(n, vector<int>(m, 0));
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      mat[y][x] = 1;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[j][i] && mat[j][i] == 1) {
          dfs(mat, visited, j, i);
          ans++;
        }
      }
    }
    cout << ans << '\n';
    t--;
  }
  return 0;
}