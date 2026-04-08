// post-order DFS, T: O(n), S: O(h) stack frames

#include <cstddef>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) { return root; }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) { return root; } // p and q in diff subtree
        return left ? left : right; // both in same subtree
    }
};

// root == p || root == q
// post-order
// left && right
// left ? left : right
// cache behavior
// if p or q not in tree
