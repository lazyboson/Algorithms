#include<iostream>
#include<memory>
#include <vector>
#include <random>

struct Node{
    int data;
    struct Node *next; 
};

class LinkedList{
    Node* m_head;
    Node* m_tail;
    public:
    //default constructor
    LinkedList(){
        m_head = nullptr;
        m_tail = nullptr;
    }
    void addNode(int data){
        Node* temp = new Node;
        temp->data = data;
        temp->next = nullptr;
        if(m_head == nullptr){
            m_head = temp;
            m_tail = temp;
        }
        else{
            m_tail->next = temp;
            m_tail = m_tail->next;
        }
    }
    void PrintNode(){
        auto t_data = m_head;
        while(t_data){
            std::cout << t_data->data <<std::endl;
            t_data = t_data->next;
        }
    }


};

int  main(){
    LinkedList a;
    
    for(int i=0; i<10; i++){
        a.addNode(rand());
    }
    a.PrintNode();
    
}
