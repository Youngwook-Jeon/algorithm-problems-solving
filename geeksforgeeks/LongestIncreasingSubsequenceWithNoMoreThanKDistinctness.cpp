#include <bits/stdc++.h>
using namespace std;

int query(vector<int> &segTree, int node, int s, int e, int qs, int qe)
{
    if (qs <= s && e <= qe)
        return segTree[node];
    if (e < qs || s > qe)
        return 0;

    int mid = (s + e) / 2;
    return max(query(segTree, 2 * node, s, mid, qs, qe), query(segTree, 2 * node + 1, mid + 1, e, qs, qe));
}

void update(vector<int> &segTree, int node, int s, int e, int ind, int val)
{
    if (ind < s || ind > e)
        return;
    if (s == e)
    {
        segTree[node] = max(segTree[node], val);
        return;
    }

    int mid = (s + e) / 2;
    update(segTree, 2 * node, s, mid, ind, val);
    update(segTree, 2 * node + 1, mid + 1, e, ind, val);
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> dp(100001);
        vector<int> segTree(4 * 100001);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int lb = max(0, arr[i] - k);
            dp[arr[i]] = max(dp[arr[i]], query(segTree, 1, 0, 1e5, lb, arr[i] - 1) + 1);
            update(segTree, 1, 0, 1e5, arr[i], dp[arr[i]]);
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}