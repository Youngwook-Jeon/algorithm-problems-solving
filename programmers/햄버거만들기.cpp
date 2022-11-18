#include <string>
#include <vector>
#include <list>
using namespace std;

int solution1(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for(int x : ingredient){
        if(v.back() == 1 && x == 2) v.back() = 12;
        else if(v.back() == 12 && x == 3) v.back() = 123;
        else if(v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }    

    return answer;
}

int solution2(vector<int> ingredient) {
    int answer = 0;
    list<int> lst;
    int hamburger[4] = { 1, 2, 3, 1 };
    for (int i = 0; i < ingredient.size(); i++) {
        lst.push_back(ingredient[i]);
        if (lst.size() >= 4 && ingredient[i] == 1) {
            bool flag = true;
            auto iter = --lst.end();
            for (int i = 3; i >= 0; i--) {
                if (*iter != hamburger[i]) {
                    flag = false;
                }
                --iter;
            }
            
            if (flag) {
                answer++;
                lst.pop_back();
                lst.pop_back();
                lst.pop_back();
                lst.pop_back();
            }
        }
    }
    return answer;
}