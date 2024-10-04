#include <iostream>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if ((n & (n + 1)) == 0)
        {
            cout << "GeekB" << '\n';
        }
        else
        {
            cout << "GeekA" << '\n';
        }
    }
    return 0;
}