// 주어진 쿼리값에 대해 num배열의 부분집합인 수들의 합으로 쿼리값을 만들수 있는지 여부를 리턴
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<bool> subsetSum1(vector<int> num, vector<int> query)
{
    int N = query.size();
    vector<bool> ans(N, false);
    int M = num.size();
    // your code goes here
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << M); j++) {
            int idx = 0;
            int s = 0;
            int k = j;
            while (k > 0) {
                if ((k & 1) == 1) {
                    s += num[idx];
                    if (s > query[i]) break;
                }
                idx++;
                k = k >> 1;
            }
            if (s == query[i]) {
                ans[i] = true;
                break;
            }
        }
    }
    return ans;
}

// 방법2: bitset 라이브러리 사용하기
vector<bool> subsetSum2(vector<int> num, vector<int> query)
{
    int n = query.size();
    vector<bool> ans(n);

    bitset<10000> bit;
    bit.reset();
    bit[0] = 1;

    for (int i = 0; i < num.size(); i++) {
        bit |= (bit << num[i]);
    }

    for (int i = 0; i < n; i++) {
        int x = query[i];
        bit[x] ? ans[i] = true : ans[i] = false;
    }

    return ans;
}