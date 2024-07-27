#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1e-9;
const double PI = 3.14159;

double f(double x, int a, int b)
{
    return a * cos(x) / (b * pow(x, 2) + x + 1);
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
        int a, b;
        cin >> a >> b;

        double l = -PI / 2, h = PI / 2;
        while ((h - l) >= EPS)
        {
            double mid = (l + h) / 2;
            if (f(mid - EPS, a, b) < f(mid + EPS, a, b))
            {
                l = mid;
            }
            else
            {
                h = mid;
            }
        }

        cout << setprecision(4) << fixed;
        cout << f(h, a, b) << '\n';
    }
    return 0;
}