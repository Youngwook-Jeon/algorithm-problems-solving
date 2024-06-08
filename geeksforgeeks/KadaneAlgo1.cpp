#include <climits>
#include <iostream>
using namespace std;

class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int sizeOfArray)
    {
       //code here
       long long ans = INT_MIN, temp = 0LL;
       for (int i = 0; i < sizeOfArray; i++) {
           if (temp + arr[i] <= arr[i]) {
               temp = arr[i];
           } else {
               temp += arr[i];
           }
           
           if (i != sizeOfArray - 1) {
               cout << temp << ' ';
           } else {
               cout << temp << '\n';
           }
           ans = max(temp, ans);
       }
       
       return ans;
    }
};