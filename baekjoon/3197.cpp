// https://www.acmicpc.net/problem/3197
#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int r, c, res;
bool visited[1500][1500];
string lake[1500];
queue<pair<int, int> > q;
vector<pair<int, int> > swans;
queue<pair<int, int> > water;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> lake[i];
    for (int j = 0; j < c; j++) {
      auto loc = make_pair(j, i);
      if (lake[i][j] == 'L') {
        swans.push_back(loc);
        lake[i][j] = '.';
        water.push(loc);
      } else if (lake[i][j] == '.') {
        water.push(loc);
      }
    }
  }

  q.push(swans[0]);
  visited[swans[0].second][swans[0].first] = true;

  while (true) {
    queue<pair<int, int> > nextDayReachable;
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < c && ny >= 0 && ny < r && !visited[ny][nx]) {
          auto next = make_pair(nx, ny);
          if (swans[1] == next) {
            cout << res << '\n';
            return 0;
          } else if (lake[ny][nx] == '.') {
            q.push(next);
          } else {
            nextDayReachable.push(next);
          }
          visited[ny][nx] = true;
        }
      }
    }

    res++;
    q = nextDayReachable;

    int nowWaterLocations = water.size();
    while (nowWaterLocations > 0) {
      auto p = water.front();
      water.pop();
      int x = p.first;
      int y = p.second;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < c && ny >= 0 && ny < r && lake[ny][nx] == 'X') {
          water.push(make_pair(nx, ny));
          lake[ny][nx] = '.';
        }
      }
      nowWaterLocations--;
    } 
  }
  return 0;
}