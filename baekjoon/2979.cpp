// https://www.acmicpc.net/problem/2979
#include <iostream>
using namespace std;

int a[99];
int one, two, three;
int b, c;
int sum;

int main() {
    cin >> one >> two >> three;

    for (int i = 0; i < 3; i++) {
        cin >> b >> c;
        for (int j = 0; j < 99; j++) {
            if (j >= b - 1 and j <= c - 2) {
                a[j]++;
            }
        }
    }

    for (int j = 0; j < 99; j++) {
        switch (a[j]) {
            case 1:
                sum += one;
                break;
            case 2:
                sum += two * 2;
                break;
            case 3:
                sum += three * 3;
                break;
        }
    }

    printf("%d", sum);
    return 0;
}