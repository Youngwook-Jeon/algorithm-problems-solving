//{ Driver Code Starts
// Initial template for C++

// #include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;

int getMid(int s, int e) { return s + (e - s) / 2; }

void constructSTUtil(int *arr, int ss, int se, PII *st, int si)
{
    if (ss == se)
    {
        st[si].first = st[si].second = arr[ss];
        return;
    }
    int mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);

    st[si].first = min(st[si * 2 + 1].first, st[si * 2 + 2].first);
    st[si].second = max(st[si * 2 + 1].second, st[si * 2 + 2].second);

    return;
}

PII *constructST(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    PII *st = new PII[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

void updateValue(int *, PII *, int, int, int);
PII getMinMax(PII *, int *, int, int, int);

// } Driver Code Ends
// User function template for C++

// arr : given array arr
// st : segment tree of the given array arr
// n :  size of arr array
// qs and qe : index range to find Min and Max value between these indexes.
// PII :  return pair denoting min,max respectively.
// index : given index to update with new_val

PII getHelper(PII *st, int *arr, int n, int node, int ns, int ne, int qs, int qe)
{
    if (ns > qe || ne < qs)
        return PII(INT_MAX, INT_MIN);
    if (qs <= ns && ne <= qe)
        return st[node];

    int mid = (ns + ne) / 2;

    PII left = getHelper(st, arr, n, 2 * node + 1, ns, mid, qs, qe);
    PII right = getHelper(st, arr, n, 2 * node + 2, mid + 1, ne, qs, qe);
    return {min(left.first, right.first), max(left.second, right.second)};
}

PII updateHelper(int *arr, PII *st, int n, int node, int ns, int ne, int index, int new_val)
{
    if (index < ns || index > ne)
        return st[node];
    if (ns == ne)
    {
        st[node].first = new_val;
        st[node].second = new_val;
        return st[node];
    }

    int mid = (ns + ne) / 2;
    PII left = updateHelper(arr, st, n, 2 * node + 1, ns, mid, index, new_val);
    PII right = updateHelper(arr, st, n, 2 * node + 2, mid + 1, ne, index, new_val);
    return st[node] = {min(left.first, right.first), max(left.second, right.second)};
}

// Function to update a value in input array and segment tree.
PII getMinMax(PII *st, int *arr, int n, int qs, int qe)
{
    // add code here
    return getHelper(st, arr, n, 0, 0, n - 1, qs, qe);
}

// Function to return minimum and maximum of elements in range from index
// qs (quey start) to qe (query end).
void updateValue(int *arr, PII *st, int n, int index, int new_val)
{
    // add code here
    updateHelper(arr, st, n, 0, 0, n - 1, index, new_val);
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

        PII *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--)
        {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G')
            {
                cin >> L >> R;
                PII ans = getMinMax(st, arr, num, L, R);
                cout << ans.first << " " << ans.second << endl;
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