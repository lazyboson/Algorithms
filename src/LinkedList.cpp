#include <iostream>
#include <memory>

template<typename T>
struct ListNode {
    /* data */
    T data;
    std::shared_ptr<ListNode<T>> next;
};

std::shared_ptr<ListNode<int>> SearchList(std::shared_ptr<ListNode<int> > L, int key){
    while(L && L->data != key){
        L = L->next;
    }
    //if key was not present, L will becme null
    return L;
}

void InsertAfter(const std::shared_ptr<ListNode<int>> &node, const std::shared_ptr<ListNode<int>> &new_node){
    new_node->next = node->next;
    node->next = new_node;
}

void DeleteAfter(const std::shared_ptr<ListNode<int>> &node){
    //assuming there is an existing node guarenteed
    node->next = node->next->next;
}

void PrintNode(const std::shared_ptr<ListNode<int>> &node){
    while(node){
        std::cout << node->data << std::endl;
    }
