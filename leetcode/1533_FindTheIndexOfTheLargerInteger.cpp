// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader
{
public:
    // Compares the sum of arr[l..r] with the sum of arr[x..y]
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y);

    // Returns the length of the array
    int length();
};

class Solution
{
public:
    int getIndex(ArrayReader &reader)
    {
        int n = reader.length();
        int l = 0, h = n - 1;
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (mid - l + 1 == h - mid)
            {
                if (reader.compareSub(l, mid, mid + 1, h) == 1)
                {
                    h = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                int comp = reader.compareSub(l, mid - 1, mid + 1, h);
                if (comp == 0)
                    return mid;
                else if (comp == 1)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return l;
    }
};