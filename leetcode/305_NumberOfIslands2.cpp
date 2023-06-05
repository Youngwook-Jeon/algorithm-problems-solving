#include <vector>
using namespace std;

class UF
{
public:
    vector<int> parent, rank;
    int count;

    UF(int size)
    {
        parent.resize(size, -1);
        rank.resize(size, 0);
        count = 0;
    }

    void addLand(int ind)
    {
        if (parent[ind] != -1)
            return;

        parent[ind] = ind;
        count++;
    }

    bool isLand(int ind)
    {
        if (parent[ind] != -1)
            return true;
        return false;
    }

    int countIslands()
    {
        return count;
    }

    int find(int ind)
    {
        if (parent[ind] == ind)
            return ind;
        return parent[ind] = find(parent[ind]);
    }

    void merge(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB)
            return;

        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        count--;
    }
};

class Solution
{
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
    {
        UF uf(m * n);
        vector<int> ans;

        for (auto pos : positions)
        {
            int landInd = pos[0] * n + pos[1];
            uf.addLand(landInd);

            for (int i = 0; i < 4; i++)
            {
                int nr = pos[0] + dr[i];
                int nc = pos[1] + dc[i];
                int nInd = nr * n + nc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && uf.isLand(nInd))
                {
                    uf.merge(landInd, nInd);
                }
            }
            ans.push_back(uf.countIslands());
        }

        return ans;
    }
};