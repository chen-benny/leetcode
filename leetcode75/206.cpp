icpp#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTmp = curr->next; // save next first
            curr->next = prev; // reverse link
            prev = curr; // move prev forward
            curr = nextTmp; // move curr forward
        }

        return prev;
    }
};

// follow-up: recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // reverse rest of list
        ListNode* newHead = reverseList(head->next);

        // head becomes new tail
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
