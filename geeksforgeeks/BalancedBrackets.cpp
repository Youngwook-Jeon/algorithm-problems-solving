#include <iostream>
#include <stack>
using namespace std;

// Function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> stk;
    for (int i = 0; i < expr.length(); i++)
    {
        if (stk.empty())
            stk.push(expr[i]);
        else if ((stk.top() == '(' && expr[i] == ')') ||
                 (stk.top() == '[' && expr[i] == ']') ||
                 (stk.top() == '{' && expr[i] == '}'))
        {
            stk.pop();
        }
        else
        {
            stk.push(expr[i]);
        }
    }

    if (stk.empty())
        return true;
    return false;
}

// Driver code
int main()
{
    string expr = "{()}[]";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}