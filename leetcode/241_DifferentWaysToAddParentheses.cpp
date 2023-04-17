#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        unordered_map<string, vector<int>> table;
        return dp(expression, table);
    }

    vector<int> dp(string expr, unordered_map<string, vector<int>> &table)
    {
        if (table.find(expr) != table.end())
        {
            return table[expr];
        }

        vector<int> ans;
        for (int i = 0; i < expr.size(); i++)
        {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*')
            {
                string sub1 = expr.substr(0, i);
                vector<int> subResult1;
                if (table.find(sub1) != table.end())
                {
                    subResult1 = table[sub1];
                }
                else
                {
                    subResult1 = dp(sub1, table);
                }

                string sub2 = expr.substr(i + 1);
                vector<int> subResult2;
                if (table.find(sub2) != table.end())
                {
                    subResult2 = table[sub2];
                }
                else
                {
                    subResult2 = dp(sub2, table);
                }

                for (auto num1 : subResult1)
                {
                    for (auto num2 : subResult2)
                    {
                        switch (c)
                        {
                        case '+':
                        {
                            ans.push_back(num1 + num2);
                            break;
                        }
                        case '-':
                        {
                            ans.push_back(num1 - num2);
                            break;
                        }
                        case '*':
                        {
                            ans.push_back(num1 * num2);
                            break;
                        }
                        }
                    }
                }
            }
        }
        if (ans.empty())
        {
            ans.push_back(stoi(expr));
        }

        table[expr] = ans;

        return ans;
    }
};