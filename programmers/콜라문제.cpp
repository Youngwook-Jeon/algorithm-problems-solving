#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a) {
        int additional = (n / a) * b;
        answer += additional;
        n = additional + n % a;
    }
    return answer;
}