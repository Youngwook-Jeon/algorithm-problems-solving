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

int ans = 0;
unordered_map<string, int> um;

void solve()
{
    string s;
    cin >> s;
    ans += um[s];
}

int main()
{
    FASTIO
    um.insert(make_pair("Tetrahedron", 4));
    um.insert(make_pair("Cube", 6));
    um.insert(make_pair("Octahedron", 8));
    um.insert(make_pair("Dodecahedron", 12));
    um.insert(make_pair("Icosahedron", 20));

    forEachTestCase solve();

    cout << ans << newl;

    return 0;
}
