#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s, '.'); // 세번째 인수는 delimiter
    
    for (char ch : s) {
        cout << ch << ",";
    }
    cout << s << endl;
    return 0;
}