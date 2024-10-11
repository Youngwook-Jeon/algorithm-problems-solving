#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        char top = st.top();
        if (s[i] == top)
            continue;
        st.push(s[i]);
    }

    cout << n - st.size() << '\n';

    return 0;
}