#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int arr[101] = {
            0,
        };
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr[num]++;
        }
        int ans = 0;
        for (int i = 0; i <= 100; i++)
        {
            ans += (arr[i] / 3);
        }
        cout << ans << '\n';
    }

    return 0;
}
