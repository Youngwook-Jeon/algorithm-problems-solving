#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;
const int INF = 987654321;
int r, c, n;
int dx[] = { 0, 1, 0, -1 };
int dy[] = {-1, 0, 1, 0 };
char dungeon[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int height[MAX_SIZE];
vector<pair<int, int> > air_cluster;
bool cluster_map[MAX_SIZE][MAX_SIZE];

void bfs(int a, int b) {
  queue<pair<int, int> > q;
  q.push({ b, a });
  visited[a][b] = true;

  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < c && ny >= 0 && ny < r && !visited[ny][nx]) {
        if (dungeon[ny][nx] == 'x') {
          q.push({ nx, ny });
          visited[ny][nx] = true;
        }
      }
    }
  }
}

bool handle_air_cluster() {
  // 값 초기화
  air_cluster.clear();
  memset(cluster_map, false, sizeof(cluster_map));
  memset(visited, false, sizeof(visited));
  bool exist_air_cluster = false;

  for (int i = 0; i < c; i++) {
    if (dungeon[r - 1][i] == 'x' && !visited[r - 1][i]) {
      bfs(r - 1, i);
    }
  }

  for (int j = 0; j < r; j++) {
    for (int i = 0; i < c; i++) {
      if (dungeon[j][i] == 'x' && !visited[j][i]) {
        exist_air_cluster = true;
        air_cluster.push_back({ i, j }); // 좌표
        cluster_map[j][i] = true;
      }
    }
  }

  return exist_air_cluster;
}

int compute_dist(int x, int y) {
  int res = 0;
  for (int i = y + 1; i < r; i++) {
    if (dungeon[i][x] == 'x') {
      if (cluster_map[i][x]) res = INF;
      return res;
    }
    res++;
  }
  return res;
}

void remake_dungeon() {
  int dist = INF;
  for (auto component : air_cluster) {
    int x = component.first;
    int y = component.second;
    int tmp = compute_dist(x, y);
    if (tmp == INF) continue;
    dist = min(tmp ,dist);
  }

  // y값이 더 큰 클러스터 부분부터 떨어져야 함!
  sort(air_cluster.begin(), air_cluster.end());

  for (int i = air_cluster.size() - 1; i >= 0; i--) {
    int x = air_cluster[i].first;
    int y = air_cluster[i].second;
    dungeon[y][x] = '.';
    dungeon[y + dist][x] = 'x';
  }
}

bool play_by_player(char player, int h) {
  bool flag = false;
  if (player == 'L') {
    for (int i = 0; i < c; i++) {
      if (dungeon[r - h][i] == 'x') {
        dungeon[r - h][i] = '.';
        flag = true;
        break;
      }
    }
  } else {
    for (int i = c - 1; i >= 0; i--) {
      if (dungeon[r - h][i] == 'x') {
        dungeon[r - h][i] = '.';
        flag = true;
        break;
      }
    }
  }

  return flag;
}

void play() {
  for (int i = 0; i < n; i++) {
    char player;
    if (i % 2 == 0) player = 'L';
    else player = 'R';
    bool isHit = play_by_player(player, height[i]);
    if (!isHit) continue;
    if (handle_air_cluster()) {
      remake_dungeon();
    }
  }
}

void print() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << dungeon[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> dungeon[i][j];
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> height[i];
  }

  play();
  print();

  return 0;
}