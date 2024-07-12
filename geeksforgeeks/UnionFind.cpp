class Solution
{
public:
    // Function to merge two nodes a and b.
    void union_(int a, int b, int par[], int rank1[])
    {
        // code here
        int parA = find(a, par);
        int parB = find(b, par);
        if (rank1[parA] < rank1[parB])
        {
            par[parA] = parB;
        }
        else
        {
            par[parB] = parA;
        }
        if (rank1[parA] == rank1[parB])
            rank1[parA]++;
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[])
    {
        // code here
        return find(x, par) == find(y, par);
    }

    int find(int a, int par[])
    {
        if (par[a] == a)
            return a;

        return par[a] = find(par[a], par);
    }
};