#include <iostream>
#include <vector>
#include <algorithm>
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
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        int ans = 0;
        while (k != 0 && i < n && arr[i] != 4 && arr[i] != 5 && arr[i] != 6)
        {
            if (arr[i] == 1)
                arr[i] = 6;
            else if (arr[i] == 2)
                arr[i] = 5;
            else
                arr[i] = 4;
            ans += arr[i];
            k--;
            i++;
        }

        while (i < n)
        {
            ans += arr[i];
            i++;
        }

        cout << ans << '\n';
    }
}
