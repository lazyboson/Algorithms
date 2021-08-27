#include <iostream>
#include <memory>
#include <vector>
#include <random>

typedef std::shared_ptr<ListNode<int>> _LL;
template<typename T>
struct ListNode {
    /* data */
    T data;
    std::shared_ptr<ListNode<T>> next;
};

class LinkedList{
    _LL m_head = nullptr;
    _LL m_tail = nullptr;
    public:
    void CreateLinkedList(int data){
        _LL temp(new ListNode<int>()); 

    }
};