#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y;
    cin >> y;

    if (y % 4 != 0)
    {
        cout << 365;
    }
    else if (y % 100 != 0)
    {
        cout << 366;
    }
    else if (y % 400 != 0)
    {
        cout << 365;
    }
    else
    {
        cout << 366;
    }

    return 0;
}