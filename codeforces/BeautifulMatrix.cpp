#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
                y = i, x = j;
        }
    }

    cout << abs(3 - y) + abs(3 - x) << '\n';

    return 0;
}