#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < k; i++)
        {
            int q;
            cin >> q;

            int l = 0, h = n - 1;
            while (l < h)
            {
                int mid = l + (h - l) / 2;
                if (arr[mid] > q)
                {
                    h = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (arr[h] <= q)
                cout << -1 << '\n';
            else
                cout << arr[h] << '\n';
        }
    }

    return 0;
}