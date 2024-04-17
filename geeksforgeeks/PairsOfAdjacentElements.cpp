class Solution
{
public:
    int adjacentPairs(int N, int arr[])
    {
        // code here
        int ans = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] + 1 == arr[i + 1])
                ans++;
        }

        return ans;
    }
};