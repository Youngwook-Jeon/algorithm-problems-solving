// Given a rope of length N meters, and the rope can be cut in only 3 sizes A, B and C.
// The task is to maximizes the number of cuts in rope.
#include <iostream>
#include <algorithm>
using namespace std;

int maxRopes(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n <= -1)
        return -1;

    int ans = max(maxRopes(n - a, a, b, c), max(maxRopes(n - b, a, b, c), maxRopes(n - c, a, b, c)));

    if (ans == -1)
        return -1;

    return ans + 1;
}

int main()
{
    int n = 17, a = 11, b = 10, c = 3;
    int ans = maxRopes(n, a, b, c);
    cout << ans << endl;
    return 0;
}