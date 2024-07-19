#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int ans;
    int l = 0, h = arr.size() - 1;
    while (l < h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] >= target)
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (arr[h] < target)
        return -1;
    return arr[h];
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
            int target;
            cin >> target;
            cout << binarySearch(arr, target) << '\n';
        }
    }
    return 0;
}