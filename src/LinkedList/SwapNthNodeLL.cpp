/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* previous;
        int cnt = 1;
        int totalNode = 0;
        ListNode* tracker = head;
        while(tracker){
            totalNode++;
            tracker = tracker->next;
        }
        //--n from the front
         n = (totalNode - n) + 1;
        while(temp) {
           if(cnt == n && n==1){
               head = temp->next;
               delete(temp);
               return head;
           }
           else{
               if(cnt==n){
                   previous->next = temp->next;
                   temp->next = nullptr;
                   delete(temp);
                   return head;
               }
               else{
                   previous = temp;
                   temp = temp->next;
                   cnt++;
               }
           }
        }
        return head;
    }
};