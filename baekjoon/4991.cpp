// https://www.acmicpc.net/problem/4991
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Info {
  pair<int, int> loc;
  int distance;
  int bitmask;
};

int w, h, k;
bool visited[20][20][1 << 10];
int mp[20][20];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
pair<int, int> st;

int solve() {
  queue<Info> q;
  q.push({{st.first, st.second}, 0, 0});

  while (!q.empty()) {
    Info now = q.front();
    q.pop();
    pair<int, int> now_loc = now.loc;
    int now_dist = now.distance;
    int now_mask = now.bitmask;
    if (now_mask == (1 << k) - 1) return now_dist;

    for (int i = 0; i < 4; i++) {
      int next_r = now_loc.first + dr[i];
      int next_c = now_loc.second + dc[i];
      int next_mask = now_mask;
      int next_dist = now_dist + 1;
      if (next_r < 0 || next_r >= h || next_c < 0 || next_c >= w || mp[next_r][next_c] == -1) continue;
      if (mp[next_r][next_c] > 0) next_mask |= (1 << (mp[next_r][next_c] - 1));
      if (visited[next_r][next_c][next_mask]) continue;
      visited[next_r][next_c][next_mask] = true;
      q.push({{next_r, next_c}, next_dist, next_mask});
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  while (true) {
    cin >> w >> h;
    if (w == 0) break;
    memset(visited, false, sizeof(visited));
    string s;
    k = 0;
    for (int i = 0; i < h; i++) {
      cin >> s;
      for (int j = 0; j < w; j++) {
        if (s[j] == 'o') {
          st = {i, j};
          mp[i][j] = 0;
        } else if (s[j] == '.') {
          mp[i][j] = 0;
        } else if (s[j] == '*') {
          mp[i][j] = ++k;
        } else {
          mp[i][j] = -1;
        }
      }
    }

    cout << solve() << '\n';
  }
  return 0;
}