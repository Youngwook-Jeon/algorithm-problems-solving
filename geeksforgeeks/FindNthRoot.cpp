#include <iostream>
#include <iomanip>
using namespace std;

double findNthRoot(double x, int n)
{
    double l, h;
    if (x >= 0 && x <= 1)
    {
        l = x;
        h = 1;
    }
    else
    {
        l = 1;
        h = x;
    }

    double eps = 0.00000001;
    double guess = (l + h) / 2;
    while (abs(pow(guess, n) - x) >= eps)
    {
        if (pow(guess, n) > x)
        {
            h = guess;
        }
        else
        {
            l = guess;
        }
        guess = (l + h) / 2;
    }

    return guess;
}

int main()
{
    double x = 5;
    int n = 3;
    cout << fixed << setprecision(16) << findNthRoot(x, n);
    return 0;
}