// https://www.acmicpc.net/problem/1620
// 포켓몬 이름이 나열된 도감이 주어졌다. 이때 도감 번호가 입력될 때 -> 포켓몬 이름, 포켓몬 이름이 입력 -> 도감 번호 가 출력되게 하기
#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, m;
map<string, int> mp1;
map<int, string> mp2;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp1[s] = i + 1;
        mp2[i + 1] = s;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (atoi(s.c_str()) == 0) {
            cout << mp1[s] << "\n";
        } else {
            cout << mp2[atoi(s.c_str())] << "\n";
        }
    }
    
    return 0;
}