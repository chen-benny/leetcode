// post-order dfs, T: O(n), S: O(h)

#include <cstddef> // nullptr
#include <algorithm> // std::max
#include <cstdlib> // std::abs

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

private:
    int height(TreeNode* node) {
        if (!node) { return 0; }

        int left = height(node->left);
        if (left == -1) { return -1; }
        int right = height(node->right);
        if (right == -1) { return -1; }

        if (std::abs(left - right) > 1) { return -1; }
        return 1 + std::max(left, right);
    }
};

// -1 sentinel: flag both unbalanced and short-circuits for early exit
// post-order mandatory + early-exit
// cache left subtree fully visited before the right
// return int over bool: preserve height information as well as bool
