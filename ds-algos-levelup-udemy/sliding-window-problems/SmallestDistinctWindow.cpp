// 주어진 문자열에서 서로 다른 문자들을 모두 포함하는 가장 작은 윈도우 찾기
#include<string>
#include <unordered_set>
#include <climits>
using namespace std;

const int MAX_CHARS = 256;

string smallestWindow(string str){
    //Complete this method
    int n = str.length();
    if (n <= 1) return str;
    unordered_set<char> set;
    for (char c : str) {
        set.insert(c);
    }
    int dist_chars = set.size();
    
    int cur_start = 0, start_ind = -1, min_len = INT_MAX;
    int count = 0;
    // 빈도를 저장할 배열
    int fs[MAX_CHARS] = {0}; 
    for (int i = 0; i < n; i++) {
        fs[str[i]]++;
        if (fs[str[i]] == 1) {
            count += 1;
        }
        
        if (count == dist_chars) {
            while (fs[str[cur_start]] > 1) {
                fs[str[cur_start]] -= 1;
                cur_start++;
            }
            
            int len_window = i - cur_start + 1;
            if (len_window < min_len) {
                min_len = len_window;
                start_ind = cur_start;
            }
        }
    }
    return str.substr(start_ind, min_len);
}