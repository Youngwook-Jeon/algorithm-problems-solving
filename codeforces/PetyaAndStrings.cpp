#include <bits/stdc++.h>
using namespace std;

int toIntVal(char c)
{
    if (c <= 'Z')
        return c - 'A';
    return c - 'a';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (toIntVal(s1[i]) < toIntVal(s2[i]))
        {
            ans = -1;
            break;
        }
        else if (toIntVal(s1[i]) > toIntVal(s2[i]))
        {
            ans = 1;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}