
/*
 Leetcode -- https://leetcode.com/problems/swap-nodes-in-pairs/
 Author - Ashutosh Pandey
*/

struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head;
        ListNode *previous;
        int cntEven = 1;
        //single node or no node in list -- no swap needed return it
        if(head == nullptr)
            return head;
        if(head->next == nullptr)
            return head;
        while(temp){
            //swap is needed
            if(cntEven%2 == 0) {
                int swap = temp->val;
                temp->val = previous->val;
                previous->val = swap;
            }
             previous = temp;
             temp=temp->next;
             cntEven++;  
        }
        return head;
    }
};