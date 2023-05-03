/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */
int read4(char *buf4);

class Solution
{
public:
    int i4 = 0, n4 = 0;
    char buf4[4];
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int ans = 0;
        while (ans < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buf4))))
        {
            buf[ans++] = buf4[i4++];
        }

        return ans;
    }
};