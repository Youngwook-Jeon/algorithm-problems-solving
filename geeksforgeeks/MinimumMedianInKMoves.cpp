#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<int> &arr, int n, int k, int t)
{
    int cnt = 0;
    for (int i = 0; i <= n / 2; i++)
    {
        if (arr[i] > t)
            cnt++;
        if (cnt > k)
            return false;
    }

    return true;
}

int main()
{
    // code
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 1, h = arr[n / 2];
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (check(arr, n, k, mid))
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << h << '\n';
    return 0;
}