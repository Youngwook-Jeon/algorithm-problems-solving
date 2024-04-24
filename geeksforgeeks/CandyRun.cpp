#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, q;
        cin >> n >> q;
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            um[num] = i + 1;
        }

        int ph = 0, fe = 0;
        for (int i = 0; i < q; i++)
        {
            int cnt = 0;
            cin >> cnt;
            ph += um[cnt];
            fe += (n + 1) - um[cnt];
        }

        if (ph > fe)
        {
            cout << ph << ' ' << fe << " Ferb" << '\n';
        }
        else if (ph < fe)
        {
            cout << ph << ' ' << fe << " Phineas" << '\n';
        }
        else
        {
            cout << ph << ' ' << fe << " Candice" << '\n';
        }
    }
    return 0;
}