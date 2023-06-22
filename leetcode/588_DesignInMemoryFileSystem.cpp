#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct File
{
    unordered_map<string, File *> next;
    bool isFile;
    string content;
    File() : isFile(false), content("") {}
};

class FileSystem
{
public:
    File *root;
    FileSystem()
    {
        root = new File();
    }

    File *goToPathFolder(string path)
    {
        File *cur = root;
        stringstream s(path);
        string folder;
        while (getline(s, folder, '/'))
        {
            if (folder.size())
            {
                if (cur->next[folder] == NULL)
                {
                    cur->next[folder] = new File();
                }
                cur = cur->next[folder];
            }
        }
        return cur;
    }

    vector<string> ls(string path)
    {
        File *cur = goToPathFolder(path);
        if (cur->isFile)
            return {path.substr(path.find_last_of('/') + 1)};

        vector<string> ans;
        for (auto &p : cur->next)
        {
            ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    void mkdir(string path)
    {
        goToPathFolder(path);
    }

    void addContentToFile(string filePath, string content)
    {
        File *cur = goToPathFolder(filePath);
        cur->content += content;
        cur->isFile = true;
    }

    string readContentFromFile(string filePath)
    {
        File *cur = goToPathFolder(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */