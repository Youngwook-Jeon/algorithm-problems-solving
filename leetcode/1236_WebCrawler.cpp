#include <string>
#include <queue>
#include <unordered_set>
#include <functional>
using namespace std;
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class HtmlParser
{
public:
    vector<string> getUrls(string url);
};

class Solution
{
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        function<string(string)> getHostname = [](string url) -> string
        {
            int pos = min(url.size(), url.find('/', 7));
            return url.substr(7, pos - 7);
        };

        queue<string> q;
        unordered_set<string> us;
        q.push(startUrl);
        us.insert(startUrl);
        string startHostname = getHostname(startUrl);

        while (!q.empty())
        {
            string url = q.front();
            q.pop();

            for (string next : htmlParser.getUrls(url))
            {
                if (getHostname(next) == startHostname && us.find(next) == us.end())
                {
                    q.push(next);
                    us.insert(next);
                }
            }
        }

        return vector<string>(us.begin(), us.end());
    }
};