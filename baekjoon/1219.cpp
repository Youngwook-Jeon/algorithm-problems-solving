// https://www.acmicpc.net/problem/1219
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
typedef long long ll;

struct Edge {
  int s, e, t;

  Edge(int s, int e, int t):
    s(s), e(e), t(t) {};
};

int n, m, st, ed;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> st >> ed >> m;
  vector<Edge> lst(m, Edge(0, 0, 0));
  vector<int> get_money(n);
  vector<ll> totals(n, LLONG_MIN);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    lst[i] = Edge(a, b, c);
  }

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    get_money[i] = a;
  }

  totals[st] = get_money[st];

  for (int i = 0; i < n + 100; i++) {
    for (Edge eg: lst) {
      if (totals[eg.s] == LLONG_MIN) continue;
      else if (totals[eg.s] == LLONG_MAX) {
        totals[eg.e] = LLONG_MAX;
      } else if (totals[eg.e] < totals[eg.s] + get_money[eg.e] - eg.t) {
        totals[eg.e] = totals[eg.s] + get_money[eg.e] - eg.t;

        if (i >= n) totals[eg.e] = LLONG_MAX;
      }
    }
  }

  if (totals[ed] == LLONG_MIN) {
    cout << "gg" << "\n";
  } else if (totals[ed] == LLONG_MAX) {
    cout << "Gee" << "\n";
  } else {
    cout << totals[ed] << "\n";
  }

  return 0;
}