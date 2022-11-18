#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for (string s : babbling) {
        int now = 0;
        bool flag = true;
        string prev = "";
        while (now < s.length()) {
            if (s[now] == 'a' && now + 2 < s.length()) {
                if (s[now + 1] != 'y' || s[now + 2] != 'a') {
                    flag = false;
                    break;
                } else if (prev == "aya") {
                    flag = false;
                    break;
                } else {
                    now += 3;
                    prev = "aya";
                }
            }
            
            else if (s[now] == 'y' && now + 1 < s.length()) {
                if (s[now + 1] != 'e') {
                    flag = false;
                    break;
                } else if (prev == "ye") {
                    flag = false;
                    break;
                } else {
                    now += 2;
                    prev = "ye";
                }
            }
            
            else if (s[now] == 'w' && now + 2 < s.length()) {
                if (s[now + 1] != 'o' || s[now + 2] != 'o') {
                    flag = false;
                    break;
                } else if (prev == "woo") {
                    flag = false;
                    break;
                } else {
                    now += 3;
                    prev = "woo";
                }
            }
            
            else if (s[now] == 'm' && now + 1 < s.length()) {
                if (s[now + 1] != 'a') {
                    flag = false;
                    break;
                } else if (prev == "ma") {
                    flag = false;
                    break;
                } else {
                    now += 2;
                    prev = "ma";
                }
            }
            
             else {
                 flag = false;
                 break;
             }
        }
        
        if (flag) {
            answer++;
        }
    }
    return answer;
}