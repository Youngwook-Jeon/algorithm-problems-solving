#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // code
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
            int l, r;
            cin >> l >> r;

            auto it_l = lower_bound(arr.begin(), arr.end(), l);
            if (it_l == arr.end())
            {
                cout << 0 << '\n';
                continue;
            }

            auto it_r = upper_bound(arr.begin(), arr.end(), r);
            cout << it_r - it_l << '\n';
        }
    }
    return 0;
}