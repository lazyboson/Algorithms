/*Leetcode -- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
    ListNode* swapNodes(ListNode* head, int k) {
        int NodeCount = 0;
        ListNode* temp = head;
        while(temp){
            NodeCount++;
            temp = temp->next;
        }
        int kFromLast = (NodeCount-k);
        ListNode* fromStart = head;
        ListNode* atEnd = head;
        k--;
        while(k--){
            fromStart = fromStart->next;
        }
        while(kFromLast--){
            atEnd = atEnd->next;
        }
        if(fromStart != nullptr && atEnd != nullptr){
             int swap = fromStart->val;
             fromStart->val = atEnd->val;
             atEnd->val = swap;
        }
    
        return head;
    }
};