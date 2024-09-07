#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int a = ans, b = i;
        if (a < b)
        {
            swap(a, b);
        }
        ans = arr[a][b];
    }

    cout << ans << '\n';
    return 0;
}