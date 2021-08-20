// 가로 W, 세로 H인 판이 주어졌고 선이 그어져 정사각형들로 구역이 나뉘어져 있음
// 이때 그 구역에 놓을 수 있는 타워 들의 좌표가 배열로 주어진다
// 각 타워는 체스의 룩 처럼 같은 로우, 컬럼에 존재하는 영역들을 모두 수비한다
// 우리가 구해야 할 것은 각 타워들이 커버하지 못하는 영역중 가장 큰 영역의 넓이를 구하는 것
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int defkin(int W, int H, vector<pair<int, int> > position)
{
  // your code goes here
  vector<pair<int, int> > v = position;
  vector<ll> x, y;
  x.push_back(0);
  y.push_back(0);

  for (int i = 0; i < v.size(); i++)
  {
    x.push_back(v[i].first);
    y.push_back(v[i].second);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  ll maxx = INT_MIN, maxy = INT_MIN;
  for (int i = 0; i < x.size() - 1; i++)
  {
    maxx = max(maxx, x[i + 1] - x[i] - 1);
    maxy = max(maxy, y[i + 1] - y[i] - 1);
  }
  maxx = max(maxx, W - x[x.size() - 1]);
  maxy = max(maxy, H - y[y.size() - 1]);

  return maxx * maxy;
}