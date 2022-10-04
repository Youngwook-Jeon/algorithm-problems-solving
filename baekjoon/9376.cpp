// https://www.acmicpc.net/problem/9376
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 50000

int n, h, w, ans = MAX;
string prison[102];
vector<pair<int, int> > prisoners;
bool visited[3][102][102];
int table[3][102][102];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0, 1, 0, -1 };

struct Edge {
  pair<int, int> vertex;
  int count;

  bool operator<(const Edge &other) const {
    return this->count > other.count;
  }
};

void dijkstra(int person, int row, int col) {
  priority_queue<Edge> pq;
  table[person][row][col] = 0;
  pq.push({make_pair(row, col), 0});

  while (!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    pair<int, int> v = e.vertex;
    int c = e.count;
    if (visited[person][v.first][v.second]) continue;

    visited[person][v.first][v.second] = true;
    for (int i = 0; i < 4; i++) {
      int nr = v.first + dr[i];
      int nc = v.second + dc[i];

      if (nr >= 0 && nr <= h + 1 && nc >= 0 && nc <= w + 1 
        && !visited[person][nr][nc] && prison[nr][nc] != '*') {
          int ncount = c;
          if (prison[nr][nc] == '#') ncount++;

          if (table[person][nr][nc] > ncount) {
            table[person][nr][nc] = ncount;
            pq.push({make_pair(nr, nc), ncount});
          }
      }
    }
  }
}

void solve() {
  dijkstra(0, 0, 0);
  dijkstra(1, prisoners[0].first, prisoners[0].second);
  dijkstra(2, prisoners[1].first, prisoners[1].second);
  
  for (int j = 0; j <= h + 1; j++) {
    for (int k = 0; k <= w + 1; k++) {
      if (prison[j][k] == '*') continue;

      int tmp = table[0][j][k] + table[1][j][k] + table[2][j][k];
      if (prison[j][k] == '#') {
        tmp -= 2;
      }
      ans = min(ans, tmp);
    }
  }
  
}

void init_table() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 102; j++) {
      for (int k = 0; k < 102; k++) {
        table[i][j][k] = MAX;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;
  while (n > 0) {
    cin >> h >> w;
    ans = MAX;
    prisoners.clear();
    memset(visited, false, sizeof(visited));
    init_table();

    for (int i = 1; i <= h; i++) {
      cin >> prison[i];
      prison[i] = "." + prison[i] + ".";
      for (int j = 1; j <= w; j++) {
        if (prison[i][j] == '$') {
          prisoners.push_back({ i, j });
          prison[i][j] = '.';
        }
      }
    }
    string tmp = "";
    for (int i = 0; i <= w + 1; i++) {
      tmp += ".";
    }
    prison[0] = tmp;
    prison[h + 1] = tmp;

    solve();
    cout << ans << '\n';
    n--;
  }
  return 0;
}