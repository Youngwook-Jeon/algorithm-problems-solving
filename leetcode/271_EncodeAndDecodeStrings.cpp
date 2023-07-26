#include <string>
#include <vector>
using namespace std;

class Codec
{
public:
    const string DELIMITER = ":/";

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string ret = "";
        for (auto &str : strs)
        {
            ret += to_string(str.size()) + DELIMITER + str;
        }

        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> ret;
        int i = 0;
        while (s.size())
        {
            auto found = s.find(":/", i);
            int length = stoi(s.substr(0, found));
            string partial = s.substr(found + 2, length);
            ret.push_back(partial);
            s = s.substr(found + 2 + length);
        }

        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));