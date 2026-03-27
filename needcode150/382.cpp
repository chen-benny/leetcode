// reservoir sampling. for i-th node, replace cur res with it by prob 1/i, T: O(n) per call, S: O(1)

#include <cstdlib>

class Solution {
    ListNode* head;

public:
    Solution(ListNode* head) : head(head) {}

    int getRandom() {
        int res = 0;
        int i = 1;
        ListNode* cur = head;

        while (cur) {
            if (std::rand() % i == 0) { res = cur->val; }
            cur = cur->next;
            ++i;
        }
        return res;
    }
};

/*
   - why reservoir sampling is correct
   - when to prefer array pre-collection
   - cache behavior
   ? extend to k random nodes with replacement
   ? why not just count list length then sample
*/
