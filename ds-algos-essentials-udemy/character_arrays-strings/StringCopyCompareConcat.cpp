#include <iostream>
using namespace std;

int main() {
  char a[1000] = "apple";
  char b[1000];

  cout << strlen(a) << endl;

  strcpy(b, a);
  cout << b << endl;

  cout << strcmp(a, b) << endl;

  char web[100] = "www.";
  char domain[] = "naver.com";

  strcpy(b, strcat(web, domain)); // web에 domain 문자열을 이어 붙여도 넘치지 않게 충분히 크게 잡아야 에러 발생 x
  cout << web << endl; // www.naver.com
  cout << b << endl;
  cout << strcmp(a, b) << endl;

  return 0;
}