#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        bool flag = false;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            um[arr[i]]++;
            if (!flag && um[arr[i]] > 1)
                flag = true;
        }

        if (!flag)
            cout << -1 << '\n';
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (um[arr[i]] != 1)
                {
                    cout << i + 1 << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}