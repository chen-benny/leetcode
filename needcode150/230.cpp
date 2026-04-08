// inorder dfs with early exit, T: O(h + k), S: O(h) stack frames

#include <cstddef>

class Solution {
private:
    int count = 0;
    int result = 0;

    void inorder(TreeNode* node, int k) {
        if (!node || count >= k) { return; }
        inorder(node->left, k);
        if (++count == k) { result = node->val; return; }
        inorder(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};

// iterative inorder, T: O(h + h), S: O(h) stack frames

#include <stack>
#include <cstddef>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr || !stk.empty()) {
            while (curr) { stk.push(curr); curr = curr->left; }
            curr = stk.top(); stk.pop();
            if (--k == 0) { return curr->val; }
            curr = curr->right;
        }
        return -1;
    }
};

// O(h + k)
// iterative vs recursive early exit
// augmented BST for O(logn)
// cache behavior: flat array
// morris traversal: O(1) space
