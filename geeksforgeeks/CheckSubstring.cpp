#include <iostream>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string a, b;
        cin >> a >> b;
        size_t pos = a.find(b);
        if (pos == string::npos)
            cout << -1 << '\n';
        else
            cout << pos << '\n';
    }
    return 0;
}