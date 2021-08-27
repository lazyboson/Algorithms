#include <iostream>
#include <memory>
#include <vector>
#include <random>


template<typename T>
struct ListNode {
    /* data */
    T data;
    std::shared_ptr<ListNode<T>> next;
};

std::shared_ptr<ListNode<int>> CreateLinkedList(std::shared_ptr<ListNode<int>> &head, std::shared_ptr<ListNode<int>> &maintainer, std::shared_ptr<ListNode<int>> &temp,  std::vector<int> &data){
    int counter = 0;
    for(const auto _d : data){  
        if(counter == 0){
            head->data = _d;
            head->next = nullptr;
            counter++;
        }
        else if(counter == 1) {
            maintainer->data = _d;
            maintainer->next = nullptr;
            head->next = maintainer;
        }
        else {
            temp->data = _d;
            temp->next = nullptr;
            maintainer->next = temp;
            maintainer = temp;
        }     
    }
    return head;
}

// std::shared_ptr<ListNode<int>> SearchList(std::shared_ptr<ListNode<int> > L, int key){
//     while(L && L->data != key){
//         L = L->next;
//     }
//     //if key was not present, L will becme null
//     return L;
// }

// void InsertAfter(const std::shared_ptr<ListNode<int>> &node, const std::shared_ptr<ListNode<int>> &new_node){
//     new_node->next = node->next;
//     node->next = new_node;
// }

// void DeleteAfter(const std::shared_ptr<ListNode<int>> &node){
//     //assuming there is an existing node guarenteed
//     node->next = node->next->next;
// }

void PrintNode(const std::shared_ptr<ListNode<int>> &node){
    while(node){
        std::cout << node->data << std::endl;
    }
}

//create a shorted linkedlist post merging two shorted linked list

// std::shared_ptr<ListNode<int>> MergeTwoShortedList(std::shared_ptr<ListNode<int>> L1, std::shared_ptr<ListNode<int>> L2) {
//     //create a placeholder for the result
//     std::shared_ptr<ListNode<int>> dummy_head (new ListNode <int>);
//     auto tail = dummy_head;
//     while(L1 && L2){
//         AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
//     }
//     //append the remaining node of L1 and L2
//     tail->next = L1?L1:L2;
//     return dummy_head->next;
// }

// void AppendNode(std::shared_ptr<ListNode<int>> *node, std::shared_ptr<ListNode<int>> *tail){
//     (*tail)->next = *node;
//     *tail = *node;
//     *node= (*node)->next;
// }

//reverse the linkedlist between the two nodes

// std::shared_ptr<ListNode<int>> ReverseList(std::shared_ptr<ListNode<int>> L, int start, int finish){
//     if(start==finish)
//         return L;
//     auto dummy_head = std::make_shared<ListNode<int>>(ListNode<int>{0,L});
//     auto sublist_head = dummy_head;
//     int k = 1;
    
// }

int main(){
    std::vector<int> data;
    for(int i=0; i< 10; i++){
        data.push_back(rand());
    }
    // for(const auto r:data){
    //     std::cout << r <<std::endl;
    // }
    std::shared_ptr<ListNode<int>> head (new ListNode<int>);

    std::shared_ptr<ListNode<int>> maintainer(new ListNode<int>);

    std::shared_ptr<ListNode<int>> temp(new ListNode<int>);

    head = CreateLinkedList(head, maintainer, temp, data);
    PrintNode(head);
}