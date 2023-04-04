class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0, next = 1;
        while (left != 0)
        {
            int val = 0;
            if (right - left == 0 && (right % 2) & (left % 2) == 1)
            {
                val = 1;
            }
            ans += next * val;
            next = (next << 1);
            left /= 2;
            right /= 2;
        }

        return ans;
    }
};