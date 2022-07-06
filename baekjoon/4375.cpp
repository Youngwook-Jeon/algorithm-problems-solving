// https://www.acmicpc.net/problem/4375
// Find a min number consisting of only 1 that can divided by the given number n.
#include <iostream>
using namespace std;

int n;

int main() {
  while (scanf("%d", &n) != EOF) {
    int a = 1, ans = 1;
    while (a % n != 0) {
      a = 10 * a + 1;
      a %= n;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}