#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int size = 2 * n - 1;
        int length = size - 1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int minDist = min(min(length - i, i), min(length - j, j)) + 1;
                cout << minDist << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}