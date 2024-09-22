#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll queryHelper(int node, int s, int e, int qs, int qe, ll *st)
{
    if (e < qs || s > qe)
        return 1;

    if (qs <= s && qe >= e)
        return st[node];

    int m = (s + e) / 2;
    return lcm(queryHelper(2 * node + 1, s, m, qs, qe, st), queryHelper(2 * node + 2, m + 1, e, qs, qe, st));
}

void updateHelper(int node, int s, int e, int index, int new_val, ll *st)
{
    if (index > e || index < s)
        return;

    if (s == e)
    {
        st[node] = new_val;
        return;
    }

    int m = (s + e) / 2;
    updateHelper(2 * node + 1, s, m, index, new_val, st);
    updateHelper(2 * node + 2, m + 1, e, index, new_val, st);

    st[node] = lcm(st[2 * node + 1], st[2 * node + 2]);
    return;
}

ll getLCM(ll *st, int *arr, int n, int qs, int qe)
{
    // Code here
    return queryHelper(0, 0, n - 1, qs, qe, st);
}

// Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    // Code here
    arr[index] = new_val;
    updateHelper(0, 0, n - 1, index, new_val, st);
}