#include <iostream>
#include <string>
using namespace std;
 
int binaryToDecimal(string s)
{
    // your code goes here
    int exp = 1, ans = 0;
    int sz = s.size();
    for (int i = sz - 1; i >= 0; i--) {
        ans += exp * (s[i] - '0');
        exp *= 2;
    } 
    return ans;
}
 