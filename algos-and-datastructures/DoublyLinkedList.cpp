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
    DNode<E> *prev;
    DNode<E> *next;
    friend class DLinkedList<E>;
};

template <typename E>
class DLinkedList
{
private:
    DNode<E> *head;
    DNode<E> *tail;

protected:
    void add(DNode<E> *n, const E &e); // Insert new node before n
    void remove(DNode<E> *n);          // Remove node n

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

template <typename E>
DLinkedList<E>::DLinkedList()
{
    head = new DNode<E>();
    tail = new DNode<E>();
    head->next = tail;
    tail->prev = head;
}

template <typename E>
DLinkedList<E>::~DLinkedList()
{
    while (!empty())
        removeFront();
    delete head;
    delete tail;
}

template <typename E>
bool DLinkedList<E>::empty() const
{
    return (head->next == tail);
}

template <typename E>
const E &DLinkedList<E>::front() const
{
    return head->next->elem;
}

template <typename E>
const E &DLinkedList<E>::back() const
{
    return tail->prev->elem;
}

template <typename E>
void DLinkedList<E>::add(DNode<E> *v, const E &e)
{
    DNode<E> *u = new DNode<E>();
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template <typename E>
void DLinkedList<E>::addFront(const E &e)
{
    add(head->next, e);
}

template <typename E>
void DLinkedList<E>::addBack(const E &e)
{
    add(tail, e);
}

template <typename E>
void DLinkedList<E>::remove(DNode<E> *v)
{
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

template <typename E>
void DLinkedList<E>::removeFront()
{
    remove(head->next);
}

template <typename E>
void DLinkedList<E>::removeBack()
{
    remove(tail->prev);
}

int main()
{
    DLinkedList<string> dl;
    dl.addBack("wizard");
    dl.addFront("sorcerer");
    cout << dl.back() << "\n";
    dl.addBack("paladin");
    dl.addFront("warlock");
    cout << dl.front() << "\n";
    dl.removeFront();
    dl.removeBack();
    cout << dl.back() << endl;
    return 0;
}