#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    unordered_map<string, int> sentences;
    TrieNode() {}
};

class AutocompleteSystem
{
public:
    TrieNode *root;
    TrieNode *curNode;
    TrieNode *dead;
    string curSentence;

    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++)
        {
            addToTrie(sentences[i], times[i]);
        }
        curSentence = "";
        curNode = root;
        dead = new TrieNode();
    }

    void addToTrie(string &sentence, int deg)
    {
        TrieNode *node = root;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (node->children.find(sentence[i]) == node->children.end())
            {
                node->children[sentence[i]] = new TrieNode();
            }
            node = node->children[sentence[i]];
            node->sentences[sentence] += deg;
        }
    }

    vector<string> input(char c)
    {
        if (c == '#')
        {
            addToTrie(curSentence, 1);
            curSentence = "";
            curNode = root;
            return {};
        }

        curSentence.push_back(c);
        if (curNode->children.find(c) == curNode->children.end())
        {
            curNode = dead;
            return {};
        }

        curNode = curNode->children[c];
        vector<string> sentences;
        for (auto const &p : curNode->sentences)
        {
            sentences.push_back(p.first);
        }

        sort(sentences.begin(), sentences.end(), [this](string s1, string s2) -> bool
             {
            int hot1 = curNode->sentences[s1];
            int hot2 = curNode->sentences[s2];
            if (hot1 == hot2) return s1 < s2;

            return hot1 > hot2; });

        vector<string> ans;
        for (int i = 0; i < min(3, (int)sentences.size()); i++)
        {
            ans.push_back(sentences[i]);
        }

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */