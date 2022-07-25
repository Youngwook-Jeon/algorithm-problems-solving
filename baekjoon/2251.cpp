// https://www.acmicpc.net/problem/2251
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int capacities[3];
int receiver[] = {1, 2, 0, 2, 0, 1};
int sender[] = {0, 0, 1, 1, 2, 2};
queue<pair<int, int> > q;
bool visited[201][201];
vector<int> ans;

void bfs() {
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    int aw = node.first;
    int bw = node.second;
    for (int i = 0; i < 6; i++) {
      int next[] = {aw, bw, capacities[2] - aw - bw};
      next[receiver[i]] += next[sender[i]];
      next[sender[i]] = 0;
      if (next[receiver[i]] > capacities[receiver[i]]) {
        next[sender[i]] = next[receiver[i]] - capacities[receiver[i]];
        next[receiver[i]] = capacities[receiver[i]];
      }

      if (!visited[next[0]][next[1]]) {
        visited[next[0]][next[1]] = true;
        q.push(make_pair(next[0], next[1]));

        if (next[0] == 0) {
          ans.push_back(next[2]);
        }
      } 
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;
  capacities[0] = a;
  capacities[1] = b;
  capacities[2] = c;
  pair<int, int> node = make_pair(0, 0);
  ans.push_back(c);
  visited[0][0] = true;
  q.push(node);

  bfs();

  sort(ans.begin(), ans.end());

  for (int num : ans) {
    cout << num << " ";
  }
  return 0;
}