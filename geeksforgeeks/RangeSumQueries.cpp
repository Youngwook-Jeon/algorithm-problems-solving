//{ Driver Code Starts
// Initial template for C++

// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int getMid(int s, int e)
{
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);

// } Driver Code Ends
// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree

ll getSumHelper(ll *st, int n, int node, int nl, int nr, int l, int r)
{
    if (l <= nl && nr <= r)
        return st[node];
    if (nr < l || r < nl)
        return 0;

    int mid = (nl + nr) / 2;
    return getSumHelper(st, n, 2 * node + 1, nl, mid, l, r) +
           getSumHelper(st, n, 2 * node + 2, mid + 1, nr, l, r);
}

void updateValueHelper(int *arr, ll *st, int n, int node, int nl, int nr, int index, int diff)
{
    if (index < nl || index > nr)
        return;
    if (nl == nr)
    {
        st[node] = arr[index] + diff;
        return;
    }

    int mid = (nl + nr) / 2;
    updateValueHelper(arr, st, n, 2 * node + 1, nl, mid, index, diff);
    updateValueHelper(arr, st, n, 2 * node + 2, mid + 1, nr, index, diff);
    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

// Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val)
{
    // add code here
    updateValueHelper(arr, st, n, 0, 0, n - 1, index, new_val - arr[index]);
}

// Function to return sum of elements in range from index qs (query start)
// to qe (query end).
ll getsum(ll *st, int n, int l, int r)
{
    // add code here
    return getSumHelper(st, n, 0, 0, n - 1, l, r);
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--)
        {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G')
            {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            }
            else
            {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}

// } Driver Code Ends