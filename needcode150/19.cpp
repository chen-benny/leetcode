// two-pointers one-pass, T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; i++) { fast = fast->next; }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};

/*
   - advance fast by n+1
   - dummy head
   - stack-allocated dummy
   - cache-behavior
   ? while(fast)
*/
