/*Leetcode -- https://leetcode.com/problems/palindrome-linked-list/
 Author -- Ashutosh Pandey
*/
#include<stack>

struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<int> isVisited;
        ListNode *temp = head;
        while(temp){
            isVisited.push(temp->val);
            temp = temp->next;
        }
        temp = head;
         while(temp){
            if(temp->val != isVisited.top()){
                return false;
            }
             isVisited.pop();
             temp = temp->next;
        }
        return true;
    }
};