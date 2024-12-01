// #include <bits/stdc++.h>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
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
    int y, w;
    cin >> y >> w;
    if (y > w)
        swap(y, w);
    int d = 6 - w + 1;
    int div = gcd(6, d);
    cout << d / div << '/' << 6 / div << newl;

    return 0;
}
