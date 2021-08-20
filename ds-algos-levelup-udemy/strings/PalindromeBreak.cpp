// 팰린드롬 문자열이 주어졌을 때 한 글자만 수정하여 팰린드롬이 아니게 만들기
// 단 그런 경우 중 가장 사전식 순으로 작은 문자열을 리턴하기
#include <iostream>
#include <string>
using namespace std;

string breakPalindrome(string palindrome) {
  int n = palindrome.size();
  for (int i = 0; i < n / 2; i++) {
    if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
    }
  }
  palindrome[n - 1] = 'b';
  return (n <= 1) ? "" : palindrome;
}