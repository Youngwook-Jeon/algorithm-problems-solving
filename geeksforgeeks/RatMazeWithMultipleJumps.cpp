#include <vector>
#include <iostream>
using namespace std;

//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block.
bool backtracking(vector<vector<int>>& sol, int N, vector<int> maze[], int r, int c) {
    if (r == N - 1 && c == N - 1) {
        sol[r][c] = 1;
        return true;
    }
    
    if (r > N - 1 || c > N - 1 || maze[r][c] == 0) return false;
    
    int steps = maze[r][c];
    sol[r][c] = 1;
    for (int i = 1; i <= steps; i++) {
        if (backtracking(sol, N, maze, r, c + i)) return true;
        if (backtracking(sol, N, maze, r + i, c)) return true;
    }
    sol[r][c] = 0;
    
    return false;
}

void solve(int N, vector<int> maze[]) 
{
    // write code here
    vector<vector<int>> sol(N, vector<int>(N));
    if (backtracking(sol, N, maze, 0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    } 
    
    cout << -1 << '\n';
}