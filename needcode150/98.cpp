// inorder traversal, T: O(n), S: O(h) stack frames

#include <cstddef>
#include <climits>

class Solution {
private:
    long long prev = LLONG_MIN;

    bool inorder(TreeNode* node) {
        if (!node) { return true; }
        if (!inorder(node->left)) { return false; }
        if (node->val <= prev) { return false; }
        prev = node->val;
        return inorder(node->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};

// range validation, S: O(n), S: O(h) stack frames

#include <cstddef>
#include <climits>

class Solution {
private:
    bool validate(TreeNode* node, long long lo, long long hi) {
        if (!node) { return true; }
        if (node->val <= lo || node->val >= hi) { return false; }
        return validate(node->left, lo, node->val) &&
               validate(node->right, node->val, hi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

// long long for bounds
// inorder vs range-validation
// early exit
// cache behavior
// <= for inorder check
