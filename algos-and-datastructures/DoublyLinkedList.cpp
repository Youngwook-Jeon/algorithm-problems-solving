#include <iostream>
using namespace std;

template <typename E>
class DNode;

template <typename E>
class DLinkedList;

template <typename E>
class DNode
{
private:
    E elem;
    DNode *prev;
    DNode *next;
    friend class DLinkedList<E>;
};

template <typename E>
class DLinkedList
{
private:
    DNode *head;
    DNode *tail;

protected:
    void add(DNode *n, const E &e); // Insert new node before n
    void remove(DNode *n);

public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const E &front() const;
    const E &back() const;
    void addFront(const E &e);
    void addBack(const E &e);
    void removeFront();
    void removeBack();
};