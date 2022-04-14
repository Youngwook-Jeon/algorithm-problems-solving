#include <iostream>
using namespace std;
 
const int ALPHABET_SIZE = 26;
 
// trie node
typedef struct TrieNode {
  TrieNode *children[ALPHABET_SIZE];
  bool isEndOfWord;
} TrieNode;
 
TrieNode* getNode() {
  struct TrieNode *pNode =  new TrieNode;

  pNode->isEndOfWord = false;

  for (int i = 0; i < ALPHABET_SIZE; i++)
      pNode->children[i] = NULL;

  return pNode;
}

void insert(TrieNode* root, string key) {
  TrieNode* pCrawl = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index])
      pCrawl->children[index] = getNode();

    pCrawl = pCrawl->children[index];
  }

  pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string key) {
  TrieNode* pCrawl = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index])
        return false;

    pCrawl = pCrawl->children[index];
  }

  return (pCrawl->isEndOfWord);
}