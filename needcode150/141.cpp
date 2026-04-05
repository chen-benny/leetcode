// Floyd's cycle detection. T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { return true; }
        }
        return false;
    }
};

/*
   - fast && fast->next
   - fast=2, slow=1
   - pointer comparision
   - cache behavior
   ? prove meet if cycle
*/
