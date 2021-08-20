// 주어진 스트링을 압축하되, 압축한 문자열이 원 문자열보다 길이가 길 때는 그냥 원 문자열 리턴하기
#include <iostream>
#include <string>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
  string res = "";
  int cnt = 1;
  for (int i = 1; i < str.size(); i++) {
      if (str[i] == str[i - 1]) {
          cnt++;
      } else {
          res += str[i - 1] + to_string(cnt);
          cnt = 1;
      }
  }
  res += str[str.size() - 1] + to_string(cnt);
  return (res.size() < str.size()) ? res : str;
}

int main() {
  string s = "aaaaaaaaabcccccccffzzzzzzzzzdadadadada";
  cout << compressString(s) << endl;
  return 0;
}