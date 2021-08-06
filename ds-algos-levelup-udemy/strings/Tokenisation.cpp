#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    // 1. Use stringstream
    // string input;
    // getline(cin, input);

    // stringstream ss(input);
    // string token;
    // vector<string> tokens;
    // while (getline(ss, token, ' ')) {
    //     tokens.push_back(token);
    // }

    // for (auto token : tokens) {
    //     cout << token << ",";
    // }

    // 2. Use strtok
    char input[1000];
    cin.getline(input, 1000);
    // cout << strtok(input, " ") << endl;
    // cout << strtok(NULL, " ") << endl; // internally maintains in the state of the string you passed in the last fn call, static variable
    // cout << strtok(NULL, " ") << endl;
    // cout << strtok(NULL, " ") << endl;
    char *token = strtok(input, " ");

    while (token != NULL) {
        cout << token << endl;;
        token = strtok(NULL, " ");
    }

    return 0;
}