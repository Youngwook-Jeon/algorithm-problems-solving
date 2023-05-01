#include <unordered_map>
using namespace std;

struct Node
{
    Node(int k, int v) : k(k), v(v), prev(nullptr), next(nullptr) {}
    int k, v;
    Node *prev;
    Node *next;
};

class LRUCache
{
public:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr)
    {
    }

    int get(int key)
    {
        auto p = cache.find(key);

        if (p == cache.end())
            return -1;
        else
        {
            moveToHead(p->second);
            return p->second->v;
        }
    }

    void put(int key, int value)
    {
        auto p = cache.find(key);

        if (p == cache.end())
        {
            if (capacity <= cache.size())
            {
                Node *t = tail;

                if (cache.size() == 1)
                {
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    tail->prev->next = nullptr;
                    tail = tail->prev;
                }
                cache.erase(t->k);
                delete t;
            }

            Node *node = new Node(key, value);

            if (cache.size() == 0)
            {
                head = node;
                tail = node;
            }
            else
            {
                node->next = head;
                head->prev = node;
                head = node;
            }

            cache[key] = node;
        }
        else
        {
            p->second->v = value;
            moveToHead(p->second);
        }
    }

    void moveToHead(Node *node)
    {
        if (cache.size() == 1)
            ;
        else if (node->prev == nullptr)
            ;
        else if (node->next == nullptr)
        {
            node->prev->next = nullptr;
            tail = node->prev;

            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */