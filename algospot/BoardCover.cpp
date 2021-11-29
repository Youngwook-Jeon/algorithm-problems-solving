// ㄴ 모양의 조각들을 회전시켜서 주어진 보드의 빈 공간을 메꿀수 있는지 여부를 리턴하기
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int coverType[4][3][2] = 
{ 
  {{0, 0}, {1, 0}, {0, 1}},
  {{0, 0}, {0, 1}, {1, 1}},
  {{0, 0}, {1, 0}, {1, 1}},
  {{0, 0}, {1, 0}, {1, -1}},
};

bool set(vector<vector<int> >& board, int y, int x, int type, int delta) {
  bool ok = true;
  for (int i = 0; i < 3; i++) {
      int ny = y + coverType[type][i][0];
      int nx = x + coverType[type][i][1];
      if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
          ok = false;
      } else if ((board[ny][nx] += delta) > 1) {
          ok = false;
      }
  }
  return ok;
}

int cover(vector<vector<int> >& board) {
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    if (y == -1) return 1;
    int ans = 0;
    for (int type = 0; type < 4; type++) {
        if (set(board, y, x, type, 1)) {
            ans += cover(board);
        }
        // 덮었던 블록을 다시 치우기
        set(board, y, x, type, -1);
    }
    return ans;
}

int main(){
    int cnt;
    cin >> cnt;

    int y,x;
    while(cnt--){
        cin >> y >> x;
        vector<vector<int> > board(y, vector<int>(x, 0));
        string tmp;

        for(int i=0; i < y; i++){
            cin >> tmp;
            for(int j = 0; j < tmp.size(); j++){
                if(tmp[j] == '#')
                    board[i][j] = 1;
            }
        }

        cout << cover(board) << endl;
    }
}