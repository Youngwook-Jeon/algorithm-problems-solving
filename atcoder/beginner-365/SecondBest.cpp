#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool comp(const pii &p1, const pii &p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pii> arr(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pii p = make_pair(a, i + 1);
        arr[i] = p;
    }

    sort(arr.begin(), arr.end(), comp);

    cout << arr[n - 2].second;
}