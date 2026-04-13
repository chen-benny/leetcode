// recursive bst deletion. T: O(h), S: O(h) stack frames

#include <cstddef>

class Solution {
private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) { node = node->left; }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) { return nullptr; }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) { return root->right; }
            if (!root->right) { return root->left; }

            TreeNode* succ = getMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};

// three deletion cases
// inorder successor over predecessor
// root->val = succ->val over pointer swap
// getMin: O(h)
// cache behavior
// deleteNode(root->right, succ->val) correctness
// iterative version
