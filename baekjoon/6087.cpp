// https://www.acmicpc.net/problem/6087
#include <iostream>
#include <queue>
using namespace std;
#define MAX 987654321

struct Edge {
  pair<int, int> pos;
  int dir;
  int count;

  bool operator <(const Edge &other) const {
    return this->count > other.count;
  }
};

int w, h;
int table[100][100];
string mp[100];
vector<pair<int, int> > targets;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void solve() {
  priority_queue<Edge> pq;
  table[targets[0].first][targets[0].second] = 0;
  Edge e{{targets[0].first, targets[0].second}, -1, 0};
  pq.push(e);

  while (!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    pair<int, int> p = e.pos;
    int now_r = p.first;
    int now_c = p.second;
    int now_dir = e.dir;
    int now_count = e.count;
    
    for (int i = 0; i < 4; i++) {
      int next_r = now_r + dr[i];
      int next_c = now_c + dc[i];
      int next_dir;

      if (next_r < 0 || next_r >= h || next_c < 0 || next_c >= w || mp[next_r][next_c] == '*') continue;

      if (now_dir == -1 || now_dir == i) {
        if (table[next_r][next_c] >= now_count) {
          table[next_r][next_c] = now_count;
          Edge next_e = {{ next_r, next_c }, i, now_count};
          pq.push(next_e);
        }
      } else {
        if (table[next_r][next_c] >= now_count + 1) {
          table[next_r][next_c] = now_count + 1;
          Edge next_e = {{ next_r, next_c }, i, now_count + 1};
          pq.push(next_e);
        }
      }
    }
  }
}

void init_table() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      table[i][j] = MAX;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> w >> h;
  init_table();
  for (int i = 0; i < h; i++) {
    cin >> mp[i];
    for (int j = 0; j < w; j++) {
      if (mp[i][j] == 'C') {
        mp[i][j] = '.';
        targets.push_back({i, j});
      }
    }
  }

  solve();

  cout << table[targets[1].first][targets[1].second] << '\n';
  return 0;
}