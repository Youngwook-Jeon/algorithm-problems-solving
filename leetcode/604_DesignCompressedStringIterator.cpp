#include <string>
#include <cctype>
using namespace std;

class StringIterator
{
public:
    string compressedString;
    char c = ' ';
    int cnt = 0, ind = 0;
    StringIterator(string compressedString) : compressedString(compressedString)
    {
    }

    char next()
    {
        if (!hasNext())
            return ' ';
        if (cnt == 0)
        {
            c = compressedString[ind];
            ind++;
            while (ind < compressedString.size() && isdigit(compressedString[ind]))
            {
                cnt = 10 * cnt + (compressedString[ind] - '0');
                ind++;
            }
        }
        cnt--;
        return c;
    }

    bool hasNext()
    {
        if (cnt != 0 || ind < compressedString.size())
            return true;
        return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */