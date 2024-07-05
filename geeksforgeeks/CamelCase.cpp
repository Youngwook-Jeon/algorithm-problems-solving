#include <iostream>
#define ALPHABET_SIZE 26
using namespace std;

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    vector<string> words;
};

TrieNode *getNode()
{
    TrieNode *newNode = new TrieNode;
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newNode->children[i] = nullptr;
    }

    return newNode;
}

void insert(TrieNode *root, string word)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (islower(word[i]))
            continue;

        int index = word[i] - 'A';
        if (pCrawl->children[index] == nullptr)
        {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
    (pCrawl->words).push_back(word);
}

void printWords(TrieNode *root)
{
    if (root->isEndOfWord)
    {
        sort((root->words).begin(), (root->words).end());
        for (auto &str : root->words)
        {
            cout << str << " ";
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        TrieNode *child = root->children[i];
        if (child != nullptr)
            printWords(child);
    }
}

bool search(TrieNode *root, string pattern)
{
    TrieNode *pCrawl = root;

    for (int i = 0; i < pattern.size(); i++)
    {
        int index = pattern[i] - 'A';
        if (pCrawl->children[index] == nullptr)
            return false;

        pCrawl = pCrawl->children[index];
    }

    printWords(pCrawl);

    return true;
}

// dict : given set of strings
// pattern : given pattern
class Solution
{
public:
    // Function to print all words in the CamelCase dictionary
    // that matches with a given pattern.
    void findAllWords(vector<string> dict, string pattern)
    {
        // code here
        TrieNode *root = getNode();
        for (auto &word : dict)
        {
            insert(root, word);
        }

        if (!search(root, pattern))
        {
            cout << "No match found";
        }
    }
};