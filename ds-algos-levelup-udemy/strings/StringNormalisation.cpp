#include <iostream>
#include <string>
using namespace std;

int skip_whitespace(const string &str, int idx) {
  while (idx < str.length() and str[idx] == ' ') {
    idx++;
  }
  return idx;
}

int normalize_word(string &str, int idx) {
  if (idx < str.length() and str[idx] != ' ') {
    str[idx] = toupper(str[idx]);
    idx++;
  }

  while (idx < str.length() and str[idx] != ' ') {
    str[idx] = tolower(str[idx]);
    idx++;
  }

  return idx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    int idx = 0;

    while (idx < copy.length()) {
      idx = skip_whitespace(copy, idx);
      idx = normalize_word(copy, idx);
    }
    
    return copy;
}