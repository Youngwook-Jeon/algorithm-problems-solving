class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n, fast = sumOfSquares(n);
        while (fast != 1 && slow != fast)
        {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return fast == 1;
    }

    int sumOfSquares(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};