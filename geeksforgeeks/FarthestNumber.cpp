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
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> prefixArr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int m = arr[n - 1];
        prefixArr[n - 1] = m;
        for (int i = n - 2; i >= 0; i--)
        {
            m = min(m, arr[i]);
            prefixArr[i] = m;
        }

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(prefixArr.begin(), prefixArr.end(), arr[i]);
            if (it - prefixArr.begin() <= i)
                cout << -1 << ' ';
            else
                cout << (it - prefixArr.begin() - 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}