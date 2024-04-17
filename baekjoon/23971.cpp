// https://www.acmicpc.net/problem/23971
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int h, w, n, m;

    cin >> h >> w >> n >> m;
    int addCol = 0, addRow = 0;
    if (w % (m + 1) != 0)
        addCol = 1;

    if (h % (n + 1) != 0)
        addRow = 1;

    int col = w / (m + 1) + addCol;
    int row = h / (n + 1) + addRow;

    cout << col * row;

    return 0;
}