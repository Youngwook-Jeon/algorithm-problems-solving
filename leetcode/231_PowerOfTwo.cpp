// Check whether the given n is a power of two without using any loop or recursion.
class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    if (n <= 0)
      return false;
    return n == (n & -n);
  }
};