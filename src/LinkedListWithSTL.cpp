#include <iostream>
#include <forward_list>
#include <deque>
#include <list>

int main(){
     std::list<int> doubly_linked_list;
     std::forward_list<int> single_linked_list;
    int start = 1;
    while(start < 100){
       doubly_linked_list.push_front(start);
       single_linked_list.push_front(start);
       start++;
    }
    for(const auto it:doubly_linked_list){
        std::cout << it << " ";
    }
    std::cout << "first list over" << std::endl;
    for(const auto it:single_linked_list){
        std::cout << it << " ";
    }
    return 0;
}