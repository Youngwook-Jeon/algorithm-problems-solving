#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

bool comp(const pii &p1, const pii &p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
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
        vector<pii> arr(n);

        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            arr.push_back({v, i + 1});
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < k; i++)
        {
            int l, r, x;
            cin >> l >> r >> x;
            auto lower = lower_bound(arr.begin(), arr.end(), pii(x, l), comp);
            if ((*lower).first != x)
            {
                cout << 0 << '\n';
                continue;
            }

            int freq = upper_bound(arr.begin(), arr.end(), pii(x, r), comp) - lower;
            cout << freq << '\n';
        }
    }
    return 0;
}