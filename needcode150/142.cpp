// Floyd's cycle detection + math, T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { break; }
        }

        if (!fast || !fast->next) { return nullptr; } // no cycle

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

/*
   - math
   - !fast || !fast->next check
   - cache behavior
   ? cycle start at head
*/
