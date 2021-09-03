// 0, 1, 2 중 하나의 숫자가 적힌 볼들을 순서대로 재배열하기
// O(N) 시간 복잡도로 해결하기
#include <vector>
using namespace std;

vector<int> sortBalls(vector<int> balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    int n = balls.size();
    // low: low 이전에는 모두 0번 공들이 놓임, high: high 이후에는 모두 2번 공들이 놓임
    int low = 0, high = n - 1;
    int mid = 0;
    while (mid <= high) {
        switch (balls[mid]) {
            case 0:
                swap(balls[low++], balls[mid++]);
                break;
            case 2:
                swap(balls[mid], balls[high--]);
                break;
            default:
                mid++;
                break;
        }
    }
        
    return balls;
}