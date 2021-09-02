// 팀이름, 팀이 원하는 순위가 적힌 페어들의 배열이 주어졌을 때, 원하는 순위에 매칭 되지 못했을 때 발생하는 badness 들의 최소합을 구하기
// badness = sum(abs(실제 순위 - 원하는 순위)) 의 최솟값
#include <iostream>
#include <vector>
using namespace std;

int badness(vector<pair<string, int> > teams) {
    int n = teams.size();
    vector<int> rank_list(n + 1, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int preferred = teams[i].second;
        if (rank_list[preferred] == 0) {
            rank_list[preferred] = 1;
        } else {
            int prev = preferred - 1;
            int next = preferred + 1;
            while (true) {
                if (prev >= 1 and rank_list[prev] == 0) {
                    rank_list[prev] = 1;
                    ans += (preferred - prev);
                    break;
                } else if (next <= n and rank_list[next] == 0) {
                    rank_list[next] = 1;
                    ans += (next - preferred);
                    break;
                }
                prev--;
                next++;
            }
        }
    }
    return ans;
}