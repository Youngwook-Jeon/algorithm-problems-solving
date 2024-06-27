#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;

        cout << (y >= -1 ? "YES" : "NO") << '\n';
    }

    return 0;
}