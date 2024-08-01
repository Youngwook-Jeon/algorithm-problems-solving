#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &x, vector<int> &y, int n, int ex, int ey, int length)
{
    int sx = x[n], sy = y[n];
    for (int i = 1; i + length - 1 <= n; i++)
    {
        int left = i, right = i + length - 1;
        int subX = x[right] - x[left - 1];
        int subY = y[right] - y[left - 1];
        int curX = sx - subX, curY = sy - subY;
        int dist = abs(ex - curX) + abs(ey - curY);
        if (length >= dist && (length % 2 == dist % 2))
            return true;
    }
    return false;
}

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ex, ey;
        cin >> ex >> ey;

        vector<int> x(n + 1);
        vector<int> y(n + 1);
        s = " " + s;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'R')
                x[i] = 1;
            else if (s[i] == 'L')
                x[i] = -1;
            else if (s[i] == 'U')
                y[i] = 1;
            else
                y[i] = -1;
        }

        for (int i = 1; i <= n; i++)
        {
            x[i] = x[i] + x[i - 1];
            y[i] = y[i] + y[i - 1];
        }

        int lo = 0, hi = n, ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(x, y, n, ex, ey, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}