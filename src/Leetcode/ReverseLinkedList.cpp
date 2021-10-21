#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = head;
        ListNode *prev;
        bool is_head = true;
        while (curr) {
            prev = curr;
            curr = curr->next;
            if (is_head) {
                head->next = nullptr;
                is_head = false;
            } else {
                prev->next = head;
                head = prev;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
