#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> sorted(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sorted[i] = arr[i];
        }

        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(sorted.begin(), sorted.end(), 2 * arr[i]);
            if (*(it - 1) == arr[i] && (it - 1) == sorted.begin())
            {
                cout << -1 << ' ';
            }
            else if (*(it - 1) == arr[i])
            {
                cout << *(it - 2) << ' ';
            }
            else
            {
                cout << *(it - 1) << ' ';
            }
        }

        cout << '\n';
    }
    return 0;
}