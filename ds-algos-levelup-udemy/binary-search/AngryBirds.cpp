// 새들이 B마리, 새들이 들어갈 수 있는 둥지들의 배열이 주어짐
// 이때 새들의 간격이 최소 d 만큼 떨어지도록 둥지에 넣을 때, 가능한 d의 값의 최대 값을 찾기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBirds(int B, int N, vector<int> nests, int sep) {
    int birds = 1;
    int location = nests[0];

    for (int i = 1; i <= N - 1; i++) {
        int current_location = nests[i];
        if (current_location - location >= sep) {
            birds++;
            location = current_location;

            if (birds == B) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int B = 3;
    vector<int> nests {1, 2, 4, 8, 9};
    sort(nests.begin(), nests.end());
    int N = nests.size();

    int s = 0;
    int e = nests[N - 1] - nests[0];
    int ans = -1;

    while (s <= e) {
        int mid = (s + e) / 2;
        bool canPlace = canPlaceBirds(B, N, nests, mid);
        if (canPlace) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << endl;
}