// dfs with global max, T: O(n), S: O(h) stack frames

#include <cstddef>
#include <algorithm>

class Solution {
private:
    int best = 0;

    int dfs(TreeNode* node) {
        if (!node) { return 0; }
        int left = dfs(node->left);
        int right = dfs(node->right);
        best = std::max(best, left + right);
        return 1 + std::max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return best;
    }
};

// return height over diameter
// best as class member
// post-order traversal
// cache behavior
// left + right over left + right + 1
// one node tree
