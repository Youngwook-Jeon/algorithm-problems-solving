// 막대기들의 길이가 주어진 배열과 어떤 정수 D가 주어졌을 때, 두 막대기의 쌍의 길이의 차이가 D보다 작게 페어를 만든다
// 이때 만들수 있는 최대의 페어의 갯수 구하기
#include <iostream>
#include <vector>
using namespace std;

int pairSticks(vector<int> length, int D)
{
  // your code goes here
  sort(length.begin(), length.end());
  int ans = 0;

  for (int i = 0; i < length.size() - 1; i++)
  {
    if (length[i + 1] - length[i] <= D)
    {
      ans++;
      i++;
    }
  }
  return ans;
}