#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define forEachTestCase    \
    long long numTestCase; \
    cin >> numTestCase;    \
    while (numTestCase--)
#define newl '\n'

void use_file_input_output()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    FASTIO
    string letters;
    set<char> sc;
    getline(cin, letters);
    for (int i = 1; i < letters.size(); i += 3)
    {
        if (letters[i] == '{' || letters[i] == '}')
            continue;

        sc.insert(letters[i]);
    }

    cout << sc.size() << newl;
    return 0;
}
