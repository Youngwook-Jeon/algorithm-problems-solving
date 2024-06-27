#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        int ptr;
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ptr = i;
            for (int j = 0; j < n; j++)
            {
                if (i != m && b[ptr] == a[j])
                    ptr++;
            }

            ans = min(ans, n + m - (ptr - i));
        }

        cout << ans << '\n';
    }

    return 0;
}
