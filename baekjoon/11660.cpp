// https://www.acmicpc.net/problem/11660
// 2차원 배열에서의 구간합구하기
#include <iostream>
using namespace std;

int arr[1025][1025], s[1025][1025];
int n, m;
int x1, y1, x2, y2;

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      arr[i][j] = a;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + arr[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << '\n';
  }
  return 0;
}
