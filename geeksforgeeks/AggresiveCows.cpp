#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &arr, int n, int c, int x)
{
    int cnt = 1;
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - prev >= x)
        {
            cnt++;
            prev = arr[i];
        }
        if (cnt == c)
            return true;
    }

    return false;
}

int main()
{
    // code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int l = 0, h = 1000000000;

        while (l < h)
        {
            int mid = l + (h - l + 1) / 2;
            if (check(arr, n, c, mid))
            {
                l = mid;
            }
            else
            {
                h = mid - 1;
            }
        }

        cout << h << '\n';
    }
    return 0;
}