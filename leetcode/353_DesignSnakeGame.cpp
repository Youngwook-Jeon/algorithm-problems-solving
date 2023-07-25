#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <string>
using namespace std;

class SnakeGame
{
public:
    int score = 0;
    pair<int, int> head;
    int width = 0, height = 0;
    list<pair<int, int>> snake;
    set<pair<int, int>> pos;
    vector<vector<int>> food;

    SnakeGame(int width, int height, vector<vector<int>> &food) : width(width), height(height), food(food)
    {
        head = {0, 0};
        snake.push_back({0, 0});
        pos.insert({0, 0});
    }

    int move(string direction)
    {
        auto nextHead = head;
        if (direction == "R")
        {
            nextHead = {head.first, head.second + 1};
        }
        else if (direction == "U")
        {
            nextHead = {head.first - 1, head.second};
        }
        else if (direction == "L")
        {
            nextHead = {head.first, head.second - 1};
        }
        else
        {
            nextHead = {head.first + 1, head.second};
        }
        int nr = nextHead.first;
        int nc = nextHead.second;
        if (nr < 0 || nr >= height || nc < 0 || nc >= width)
            return -1;

        if (score < food.size() && nr == food[score][0] && nc == food[score][1])
        {
            head = nextHead;
            snake.push_front(nextHead);
            pos.insert(nextHead);
            score++;
        }
        else if (nextHead != snake.back() && pos.find(nextHead) != pos.end())
        {
            return -1;
        }
        else
        {
            auto last = snake.back();
            snake.pop_back();
            pos.erase(last);
            head = nextHead;
            snake.push_front(nextHead);
            pos.insert(nextHead);
        }

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */