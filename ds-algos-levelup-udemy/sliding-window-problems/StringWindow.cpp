// 긴 문자열 s 와 짧은 문자열 p가 주어졌을 때, p에 등장하는 모든 문자들을(중복된 카운트까지) 포함하는 s의 윈도우 중 가장 작은 윈도우 찾기
#include <iostream>
#include <climits>
#include <string>
using namespace std;

string stringWindow(string s, string p) {
    // Array as a Freq Map
    int fp[256] = {0};
    int fs[256] = {0};

    for (int i = 0; i < p.length(); i++) {
        fp[p[i]]++;
    }

    int cnt = 0;
    int start = 0; // left contraction
    int start_index = -1; // start idx for the best window
    int min_so_far = INT_MAX; // large number
    int window_size;
    for (int i = 0; i < s.length(); i++) {
        // expand the window by including current character
        char ch = s[i];
        fs[ch]++;
        // count how many characters have been matched till now (string and pattern)
        if (fp[ch] != 0 and fs[ch] <= fp[ch]) {
            cnt += 1;
        }

        // if all characters of the pattern are found in the current window then you can start contracting
        if (cnt == p.length()) {
            // start contracting from the left to remove unwanted characters
            while (fp[s[start]] == 0 or fs[s[start]] > fp[s[start]]) {
                fs[s[start]]--;
                start++;
            }

            window_size = i - start + 1;
            if (window_size < min_so_far) {
                min_so_far = window_size;
                start_index = start;
            }
        }
    }
    if (start_index == -1) {
        return "No window found";
    }
    return s.substr(start_index, min_so_far);
}

int main() {
    string s, p;
    cin >> s >> p;

    cout << stringWindow(s, p) << endl;
    return 0;
}