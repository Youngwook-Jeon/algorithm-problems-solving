#include <bits/stdc++.h>
using namespace std;

// lps[i] := the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]
void computeLPS(string &pat, int m, vector<int> &lps)
{
    lps[0] = 0;

    int i = 1, len = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Return all occurrences of the pattern in text
vector<int> kmpSearch(string &text, string &pat)
{
    int n = text.size();
    int m = pat.size();

    vector<int> lps(m);
    vector<int> result;

    computeLPS(pat, m, lps);

    int i = 0, j = 0;
    while ((n - i) >= (m - j))
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return result;
}

int main()
{
    string text = "abbdsraaabbclbbabbch";
    string pat = "abbc";
    vector<int> result = kmpSearch(text, pat);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }

    return 0;
}