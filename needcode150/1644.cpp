// post-order DFS with found flags, T: O(n), S: O(h) stack frames

#include <cstddef>

class Solution {
private:
    bool foundP = false;
    bool foundQ = false;

    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) { return nullptr; }

        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);
        if (node == p) { foundP = true; return node; }
        if (node == q) { foundQ = true; return node; }

        if (left && right) { return node; }
        return left ? left : right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* candidate = dfs(root, p, q);
        return (foundP && foundQ) ? candidate : nullptr;
    }
};

// check node == p/node == q before recursing
// foundP/foundQ as class members
// full traversal
// p == q
// neither exist
