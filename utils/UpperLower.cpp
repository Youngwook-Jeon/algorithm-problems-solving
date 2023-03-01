#include <iostream>
#include <algorithm>
using namespace std;

string toLowerCase(string s)
{
  string ans(s.size(), ' ');
  transform(s.begin(), s.end(), ans.begin(), ::tolower);
  return ans;
}

string toUpperCase(string s)
{
  string ans(s.size(), ' ');
  transform(s.begin(), s.end(), ans.begin(), ::toupper);
  return ans;
}

int main()
{
  cout << toLowerCase("ABbCCCdeF") << '\n';
  cout << toUpperCase("ABbCCCdeF") << '\n';
  return 0;
}