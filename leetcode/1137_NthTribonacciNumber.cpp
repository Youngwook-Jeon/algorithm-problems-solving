class Solution
{
public:
    int table[38];

    int tribonacci(int n)
    {
        table[1] = table[2] = 1;
        return solve(n);
    }

    int solve(int n)
    {
        if (n <= 2 || table[n] != 0)
            return table[n];

        table[n] = solve(n - 3) + solve(n - 2) + solve(n - 1);
        return table[n];
    }
};