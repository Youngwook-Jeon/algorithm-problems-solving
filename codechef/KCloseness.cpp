#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= k;
        }
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, arr[i - 1] + k - arr[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
