#include <map>
#include <unordered_map>
using namespace std;

class Leaderboard
{
public:
    map<int, int> board;
    unordered_map<int, int> um;

    Leaderboard()
    {
    }

    void addScore(int playerId, int score)
    {
        if (um.find(playerId) == um.end())
        {
            um[playerId] = score;
            board[score] += 1;
        }
        else
        {
            int prevScore = um[playerId];
            int numPlayers = board[prevScore];

            if (numPlayers == 1)
            {
                board.erase(prevScore);
            }
            else
            {
                board[prevScore] = numPlayers - 1;
            }

            int newScore = prevScore + score;
            um[playerId] = newScore;
            board[newScore] += 1;
        }
    }

    int top(int K)
    {
        int ans = 0;
        int cnt = 0;

        for (auto rit = board.rbegin(); rit != board.rend(); ++rit)
        {
            auto [k, v] = *rit;
            for (int i = 0; i < v; i++)
            {
                ans += k;
                cnt++;

                if (cnt == K)
                    break;
            }

            if (cnt == K)
                break;
        }

        return ans;
    }

    void reset(int playerId)
    {
        int prevScore = um[playerId];
        board[prevScore] -= 1;
        if (board[prevScore] == 0)
            board.erase(prevScore);

        um.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */