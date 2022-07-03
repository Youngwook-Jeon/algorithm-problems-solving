// https://www.acmicpc.net/problem/1213
// Make a palindrome
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int arr[26];
int odd = -1, oddCases = 0;

bool isPalindrome(int *arr) {
  bool ans = true;
  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 == 1) {
      oddCases++;
      odd = i;
    }

    if (oddCases > 1) {
      ans = false;
      break;
    }
  }
  return ans;
}

string makePalindrome(int *arr) {
  string half = "";
  string ans = "";

  for (int i = 0; i < 26; i++) {
    if (arr[i] != 0) {
      int a = arr[i] / 2;
      while (a > 0) {
        half += (i + 'A');
        a--;
      }
    }
  }
  ans += half;
  reverse(half.begin(), half.end());

  if (oddCases > 0) {
    ans += odd + 'A';
  }
  ans += half;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    arr[s.at(i) - 'A']++;
  }

  if (!isPalindrome(arr)) {
    cout << "I'm Sorry Hansoo" << endl;
    return 0;
  }
  
  cout << makePalindrome(arr);

  return 0;
}