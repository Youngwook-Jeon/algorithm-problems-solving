// https://www.acmicpc.net/problem/13251
#include <iostream>
using namespace std;

int m, k, total;
int table[51];
double p_table[51];
double ans;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> table[i];
    total += table[i];
  }

  cin >> k;

  for (int i = 0; i < m; i++) {
   if (table[i] >= k) {
      p_table[i] = 1.0;
      for (int j = 0; j < k; j++) {
        p_table[i] *= ((double) (table[i] - j)) / (total - j);
      }
   }
    ans += p_table[i];
  }

  printf("%.16f", ans);
  return 0;
}