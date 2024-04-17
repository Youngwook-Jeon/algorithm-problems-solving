// https://www.acmicpc.net/problem/5073
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
            break;

        if (a < b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        if (a < c)
        {
            int tmp = a;
            a = c;
            c = tmp;
        }

        if (a >= b + c)
            cout << "Invalid" << '\n';
        else if (a == b && b == c)
            cout << "Equilateral" << '\n';
        else if (a == b || b == c || a == c)
            cout << "Isosceles" << '\n';
        else
            cout << "Scalene" << '\n';
    }
    return 0;
}