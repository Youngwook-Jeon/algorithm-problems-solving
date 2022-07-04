// https://www.acmicpc.net/problem/2023
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[5] = {1, 3, 5, 7, 9};

bool isPrime(int cur) {
  bool ans = true;
  for (int i = 2; i * i <= cur; i++) {
    if (cur % i == 0) {
      ans = false;
      break;
    }
  }
  return ans;
}

void dfs(int cur, int depth, vector<int> &ans) {
  if (isPrime(cur)) {
    if (depth == n) {
      ans.push_back(cur);
      return;
    }

    for (int next : arr) {
      dfs(10 * cur + next, depth + 1, ans);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> n;
  vector<int> ans;

  for (int i = 2; i <= 9; i++) {
    dfs(i, 1, ans);
  }

  for (int num : ans) {
    cout << num << "\n";
  }
  return 0;
}