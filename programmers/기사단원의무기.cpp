#include <string>
#include <vector>

using namespace std;

int findNumOfDivisors(int number) {
    int ans = 0;
    for (int i = 1; i * i <= number; i++) {
        if (number % i == 0) ans += 2;
        if (i * i == number) ans -= 1;
    }
    return ans;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        int divs = findNumOfDivisors(i);
        if (divs > limit) {
            divs = power;
        }
        answer += divs;
    }
    return answer;
}