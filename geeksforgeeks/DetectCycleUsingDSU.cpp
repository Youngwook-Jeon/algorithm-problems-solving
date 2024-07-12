#include <vector>
using namespace std;

class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> par(V);
        vector<int> rank(V);
        vector<vector<bool>> visited(V, vector<bool>(V));
        for (int i = 0; i < V; i++)
        {
            par[i] = i;
        }

        for (int i = 0; i < V; i++)
        {
            for (int j : adj[i])
            {
                if (!visited[i][j])
                {
                    if (find(i, par) == find(j, par))
                        return 1;

                    merge(i, j, par, rank);
                    visited[i][j] = visited[j][i] = true;
                }
            }
        }

        return 0;
    }

    int find(int n, vector<int> &par)
    {
        if (par[n] == n)
            return n;

        return par[n] = find(par[n], par);
    }

    void merge(int i, int j, vector<int> &par, vector<int> &rank)
    {
        int parI = find(i, par);
        int parJ = find(j, par);
        if (rank[parI] < rank[parJ])
        {
            swap(parI, parJ);
        }

        par[parJ] = parI;
        if (rank[parI] == rank[parJ])
            rank[parI]++;
    }
};