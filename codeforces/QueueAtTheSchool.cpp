#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve(string &q)
{
    for (int i = 0; i < q.size() - 1; i++)
    {
        if (q[i] == 'B' && q[i + 1] == 'G')
        {
            swap(q[i], q[i + 1]);
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    string q;
    cin >> q;
    for (int i = 1; i <= t; i++)
    {
        solve(q);
    }
    cout << q << '\n';

    return 0;
}