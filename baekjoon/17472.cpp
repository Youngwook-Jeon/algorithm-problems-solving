// https://www.acmicpc.net/problem/17472
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int s, e, w;

  Edge(int s, int e, int w):
    s(s), e(e), w(w) {};

  bool operator<(Edge other) const {
    return this->w > other.w;
  }
};

int n, m, ans, island_id = 1;
priority_queue<Edge> pq;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[10][10];
int parents[7];

int find(int u) {
  if (parents[u] == u) return u;
  return parents[u] = find(parents[u]);
}

void merge(int u, int v) {
  int pu = find(u);
  int pv = find(v);
  if (pu == pv) return;

  if (pu > pv) {
    swap(pu, pv);
  }
  parents[pv] = pu;
}

vector<vector<int> > bfs(int i, int j, vector<vector<int> >& mp) {
  queue<vector<int> > q;
  vector<vector<int> > ret;
  vector<int> st{i, j};
  q.push(st);
  ret.push_back(st);
  visited[i][j] = true;
  mp[i][j] = island_id;

  while (!q.empty()) {
    vector<int> now = q.front();
    q.pop();
    int r = now[0];
    int c = now[1];
    for (int i = 0; i < 4; i++) {
      int d_r = dy[i];
      int d_c = dx[i];

      while (r + d_r >= 0 && r + d_r < n && c + d_c >= 0 && c + d_c < m) {
        if (!visited[r + d_r][c + d_c] && mp[r + d_r][c + d_c] != 0) {
          mp[r + d_r][c + d_c] = island_id;
          vector<int> next{r + d_r, c + d_c};
          ret.push_back(next);
          q.push(next);
          visited[r + d_r][c + d_c] = true;
        } else {
          break;
        }

        if (d_r < 0) d_r--;
        else if (d_r > 0) d_r++;
        else if (d_c < 0) d_c--;
        else if (d_c > 0) d_c++;
      }
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  vector<vector<int> > mp(n, vector<int>(m, 0));
  vector<vector<vector<int>> > islands;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] != 0 && !visited[i][j]) {
        vector<vector<int> > an_island = bfs(i, j, mp);
        island_id++;
        islands.push_back(an_island);
      }
      
    }
  }

  for (int i = 0; i < islands.size(); i++) {
    auto island = islands[i];
    for (int j = 0; j < island.size(); j++) {
      int r = island[j][0];
      int c = island[j][1];
      int current_id = mp[r][c];

      for (int k = 0; k < 4; k++) {
        int d_r = dy[k];
        int d_c = dx[k];
        int bridge_len = 0;
        while (r + d_r >= 0 && r + d_r < n && c + d_c >= 0 && c + d_c < m) {
          if (mp[r + d_r][c + d_c] == current_id) {
            break;
          } else if (mp[r + d_r][c + d_c] != 0) {
            if (bridge_len > 1) {
              pq.push(Edge(current_id, mp[r + d_r][c + d_c], bridge_len));
            }
            break;
          } else {
            bridge_len++;
          }

          if (d_r < 0) d_r--;
          else if (d_r > 0) d_r++;
          else if (d_c < 0) d_c--;
          else if (d_c > 0) d_c++;
        }
      }
    }
  }

  for (int i = 0; i < 7; i++) {
    parents[i] = i;
  }
  int used_edges = 0;
  
  while (!pq.empty()) {
    Edge now = pq.top();
    pq.pop();
    int ps = find(now.s);
    int pe = find(now.e);
    if (ps == pe) continue;
    merge(ps, pe);
    ans += now.w;
    used_edges++;
  }

  if (used_edges == island_id - 2) {
    cout << ans << "\n";
  } else {
    cout << -1 << "\n";
  }

  return 0;
}