#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    for (int i = food.size() - 1; i > 0; i--) {
        for (int j = food[i] / 2; j > 0; j--) {
            string str = to_string(i);
            answer = str + answer + str;
        }
    }
    return answer;
}