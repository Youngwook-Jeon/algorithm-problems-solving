// https://www.acmicpc.net/problem/1991
// Traverse a tree
#include <iostream>
using namespace std;

int n;
char arr[27][2];

void preOrder(char now) {
  if (now == 0) return;

  cout << now;
  preOrder(arr[now - 'A'][0]);
  preOrder(arr[now - 'A'][1]);
}

void inOrder(char now) {
  if (now == 0) return;
  inOrder(arr[now - 'A'][0]);
  cout << now;
  inOrder(arr[now - 'A'][1]);
}

void postOrder(char now) {
  if (now == 0) return;
  postOrder(arr[now - 'A'][0]);
  postOrder(arr[now - 'A'][1]);
  cout << now;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    if (b == '.') b = 0;
    if (c == '.') c = 0;
    arr[a - 'A'][0] = b;
    arr[a - 'A'][1] = c;
  }

  preOrder('A');
  cout << "\n";
  inOrder('A');
  cout << "\n";
  postOrder('A');
  cout << "\n";

  return 0;
}