#include <cstddef>
#include <vector>
#include <algorithm>

using std::vector:
using std::max;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;

        ListNode* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        int n = values.size();
        int maxSum = 0;

        for (int i = 0; i < n / 2; i++) {
            maxSum = max(maxSum, values[i] + values[n-1-i]);
        }

        return maxSum;
    }
};

// follow-up: space O(1), actually slower
class Solution {
public:
    int pairSum(ListNode* head) {
        // find middle using fast-slow pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);

        int maxSum = 0;
        ListNode* firstHalf = head;

        while (secondHalf != nullptr) {
            maxSum = max(maxSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxSum;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTmp;
        }

        return prev;
    }
};
