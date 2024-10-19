#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool check(int x)
{
    int arr[10] = {
        0,
    };
    while (x)
    {
        int r = x % 10;
        if (arr[r] != 0)
            return false;
        arr[r]++;
        x /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y;
    cin >> y;
    int i;
    for (i = y + 1; i <= 9012; i++)
    {
        if (check(i))
            break;
    }

    cout << i << '\n';

    return 0;
}