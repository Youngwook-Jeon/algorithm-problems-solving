#include <unordered_set>
#include <algorithm>
using namespace std;

struct Robot
{
    bool move();
    void turnLeft();
    void turnRight();
    void clean();
};

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
struct pair_hash
{
    inline size_t operator()(const pair<int, int> &v) const
    {
        return v.first * 113 + v.second;
    }
};

class Solution
{
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void goBack(Robot &robot)
    {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void cleanRoom(Robot &robot)
    {
        unordered_set<pair<int, int>, pair_hash> s;
        backtrack(0, 0, 0, robot, s);
    }

    void backtrack(int dir, int r, int c, Robot &robot, unordered_set<pair<int, int>, pair_hash> &s)
    {
        s.insert({r, c});
        robot.clean();

        for (int i = 0; i < 4; i++)
        {
            int nd = (dir + i) % 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if (s.find({nr, nc}) == s.end() && robot.move())
            {
                backtrack(nd, nr, nc, robot, s);
                goBack(robot);
            }
            robot.turnRight();
        }
    }
};