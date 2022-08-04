// https://www.acmicpc.net/problem/14425
// 1. Use Trie
// #include <iostream>
// using namespace std;

// const int ALPHA_SIZE = 26;
// int n, m, ans;

// struct TrieNode {
//   TrieNode *children[ALPHA_SIZE];
//   bool isEndofWord; 
// };

// TrieNode* getNode() {
//   TrieNode *node = new TrieNode;
//   node->isEndofWord = false;

//   for (int i = 0; i < ALPHA_SIZE; i++) {
//     node->children[i] = NULL;
//   }
//   return node;
// }

// void insert(TrieNode *root, string key) {
//   TrieNode *now = root;
//   for (int i = 0; i < key.length(); i++) {
//     int index = key[i] - 'a';
//     if (!now->children[index]) {
//       now->children[index] = getNode();
//     }
//     now = now->children[index];
//   }

//   now->isEndofWord = true;
// }

// bool search(TrieNode *root, string key) {
//   TrieNode *now = root;
//   bool ret = true;
//   for (int i = 0; i < key.length(); i++) {
//     int index = key.at(i) - 'a';
//     if (!now->children[index]) {
//       ret = false;
//       break;
//     }
//     now = now->children[index];
//   }

//   if (!now->isEndofWord) ret = false;
//   return ret;
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cout.tie(NULL);
//   cin.tie(NULL);

//   cin >> n >> m;

//   TrieNode *root = new TrieNode;
//   string s = "";
//   for (int j = 0; j < n; j++) {
//     cin >> s;
//     insert(root, s);
//   }
//   for (int j = 0; j < m; j++) {
//     cin >> s;
//     if (search(root, s)) ans++;
//   }

//   cout << ans << "\n";

//   return 0;
// }

// 2. Use Map
#include <iostream>
#include <map>
using namespace std;

int n, m, ans;
map<string, bool> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> n >> m;
  string s = "";
  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s] = true;
  }
  for (int i = 0; i < m; i++) {
    cin >> s;
    if (mp[s]) ans++;
  }

  cout << ans << "\n";

  return 0;
}