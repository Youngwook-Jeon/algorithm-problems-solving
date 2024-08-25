#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            for (int j = 1; j * j <= i; j++)
            {
                if (!dp[i - j * j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                dp[i] = 1;
        }

        if (dp[n])
        {
            cout << "Alexa" << '\n';
        }
        else
        {
            cout << "Siri" << '\n';
        }
    }
    return 0;
}