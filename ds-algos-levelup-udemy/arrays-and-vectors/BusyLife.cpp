// 활동들의 (시작시각, 종료시각)으로 구성된 배열이 주어졌을 때, 가장 많이 할수있는 활동들의 수 구하기
// 정렬이 힌트
#include <vector>
#include <algorithm>
using namespace std;

bool sortBySecond(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int countActivites(vector<pair<int,int> > activities){
    //Complete this method
    sort(activities.begin(), activities.end(), sortBySecond);
    int ans = 1;
    pair<int, int> prev(activities[0]);
    int n = activities.size();

    for (auto p : activities) {
        if (p.first >= prev.second) {
            ans++;
            prev = p;
        }
    }
    
    return ans;
}