// 주어진 n x n 행렬을 시계 방향으로 90도 회전한 행렬 구하기
// 단 새로운 행렬을 만들지 말고 기존 행렬을 변형하라
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
      // your code goes here
      int n = matrix.size();
      int a = 0;
      int b = n - 1;
      
      while (a < b) {
          for (int i = 0; i < (b - a); i++) {
              swap(matrix[a][a + i], matrix[a + i][b]);
              swap(matrix[a][a + i], matrix[b][b - i]);
              swap(matrix[a][a + i], matrix[b - i][a]);
          }
          a++;
          b--;
      }
}
