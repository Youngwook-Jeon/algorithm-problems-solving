#include <iostream>
using namespace std;

template <typename E>
class SingleNode;

template <typename E>
class SinglyLinkedList;

template <typename E>
class SingleNode
{
private:
    E elem;
    SingleNode<E> *next;
    friend class SinglyLinkedList<E>;
};

template <typename E>
class SinglyLinkedList
{
private:
    SingleNode<E> *head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool empty() const;
    const E &front() const;
    void addFront(const E &e);
    void removeFront();
};

template <typename E>
SinglyLinkedList<E>::SinglyLinkedList()
    : head(nullptr) {}

template <typename E>
SinglyLinkedList<E>::~SinglyLinkedList()
{
    while (!empty())
        removeFront();
}

template <typename E>
bool SinglyLinkedList<E>::empty() const
{
    return head == nullptr;
}

template <typename E>
const E &SinglyLinkedList<E>::front() const
{
    return head->elem;
}

template <typename E>
void SinglyLinkedList<E>::addFront(const E &e)
{
    SingleNode<E> *node = new SingleNode<E>();
    node->elem = e;
    node->next = head;
    head = node;
}

template <typename E>
void SinglyLinkedList<E>::removeFront()
{
    SingleNode<E> *old = head;
    head = old->next;
    delete old;
}

int main()
{
    SinglyLinkedList<string> sll;
    sll.addFront("Cleric");
    sll.addFront("Sorcerer");
    sll.addFront("Fighter");
    sll.addFront("Rogue");
    sll.addFront("Druid");

    cout << sll.front() << '\n';
    sll.removeFront();
    cout << sll.front() << '\n';
    sll.removeFront();
    sll.removeFront();
    sll.removeFront();
    sll.removeFront();
    cout << sll.empty() << endl;
}