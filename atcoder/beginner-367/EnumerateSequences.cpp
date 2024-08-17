#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &visit)
{
    for (int i = 0; i < visit.size(); i++)
    {
        cout << visit[i] << ' ';
    }
    cout << '\n';
}

void dfs(vector<int> &arr, vector<int> &visit, int now, int sm, int n, int k)
{
    if (now == n)
    {
        if (sm % k == 0)
        {
            printArr(visit);
        }
        return;
    }

    for (int i = 1; i <= arr[now]; i++)
    {
        visit.push_back(i);
        dfs(arr, visit, now + 1, sm + i, n, k);
        visit.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> visit;
    dfs(arr, visit, 0, 0, n, k);

    return 0;
}