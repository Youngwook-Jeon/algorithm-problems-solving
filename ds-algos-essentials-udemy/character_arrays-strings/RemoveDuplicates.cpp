#include <iostream>
#include <string>
#include <set>
using namespace std;

string removeDuplicate(string s) {
    set<char> ss(s.begin(), s.end());
    string str;

    for (auto c : ss) {
        str.push_back(c);
    }

    return str;
}

int main() {
    cout << removeDuplicate("bbbbbbbaacppppww") << endl;
    return 0;
}