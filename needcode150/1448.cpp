// dfs with running max, T: O(n), S: O(h) stack frames

#include <cstddef>
#include <algorithm>
#include <climits>

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) { return 0; }
        int good = (node->val >= maxSoFar) ? 1 : 0;
        maxSoFar = std::max(maxSoFar, node->val);
        return good + dfs(node->left, maxSoFar)
                    + dfs(node->right, maxSoFar);
    }
};

// INT_MIN init
// pass by value
// preorder traversal
// cache behavior
// iterative
