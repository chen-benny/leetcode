// recursive, T: O(n), S: O(h) stack frames

#include <cstddef>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) { return true; }
        if (!p || !q) { return false; }
        if (p->val != q->val) { return false; }
        return isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};

// iterative, T: O(n), S: O(h)

#include <stack>
#include <cstddef>
#include <utility>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<std::pair<TreeNode*, TreeNode*>> stk;
        stk.push({p, q});

        while (!stk.empty()) {
            auto [a, b] = stk.top();
            stk.pop();
            if (!a && !b) { continue; }
            if (!a || !b) { return false; }
            if (a->val != b->val) { return false; }

            stk.push({a->left, b->left});
            stk.push({a->right, b->right});
        }
        return true;
    }
};

// early exit order
// stack depth O(h)
// cache behavior
// serialize then compare
// iterative
