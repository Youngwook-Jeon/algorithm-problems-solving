#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string parseTernary(string expression)
    {
        stack<char> st;
        string ans;

        for (int i = expression.size() - 1; i >= 0; i -= 2)
        {
            if (i == expression.size() - 1 || expression[i + 1] != '?')
            {
                st.push(expression[i]);
                continue;
            }

            char first = st.top();
            st.pop();
            char second = st.top();
            st.pop();

            if (expression[i] == 'T')
                st.push(first);
            else
                st.push(second);
        }

        ans += st.top();

        return ans;
    }
};