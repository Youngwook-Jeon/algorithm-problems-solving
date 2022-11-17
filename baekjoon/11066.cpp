// https://www.acmicpc.net/problem/11066
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 987654321

// table[j][i + j] := j ~ (i + j)까지의 파일들을 합치는 데 필요한 최소 비용
int table[501][501];
int su[501], arr[501];

int t, k;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> t;
  while (t > 0) {
    cin >> k;
    memset(su, 0, sizeof(su));
    memset(table, 0, sizeof(table));
    for (int i = 1; i <= k; i++) {
      cin >> arr[i];
      su[i] = su[i - 1] + arr[i];
    }

    for (int i = 1; i <= k; i++) {
      for (int j = 1; i + j <= k; j++) {
        table[j][i + j] = MAX;
        for (int k = j; k <= i + j - 1; k++) {
          table[j][i + j] = min(table[j][i + j], table[j][k] + table[k + 1][i + j] + su[i + j] - su[j - 1]);
        }
      }
    }

    cout << table[1][k] << '\n';

    t--;
  }
  return 0;
}