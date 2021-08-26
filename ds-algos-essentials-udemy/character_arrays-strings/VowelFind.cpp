#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string vowel(string S){
    // your code goes here
    unordered_set<char> ss {'a', 'e', 'i', 'o', 'u'};
    string ans;
    
    for (char c : S) {
        if (ss.find(c) != ss.end()) ans.push_back(c);
    }
    return ans;
} 