#include <iostream>
using namespace std;
// n개의 문자열 중 가장 길이가 큰 문자열 찾기

int main() {
  int n;
  cin >> n;
  cin.get();
  char sentence[1000];
  char largest[1000];
  int largest_len = 0;

  while (n--) {
    cin.getline(sentence, 1000);
    int len = strlen(sentence);
    if (len > largest_len) {
      largest_len = len;
      strcpy(largest, sentence);
    }
  }

  cout << "Largest sentence is " << largest << endl;
  return 0;
}