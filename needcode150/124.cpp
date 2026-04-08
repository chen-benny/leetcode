// post-order dfs with global max, T: O(n), S: O(h) stack frames

#include <cstddef>
#include <algorithm>
#include <climits>

class Solution {
private:
    int best = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) { return 0; }

        // clamp to 0: negative subtree contributes nothing
        int left = std::max(0, dfs(node->left));
        int right = std::max(0, dfs(node->right));

        best = std::max(best, node->val + left + right);

        return node->val + std::max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return best;
    }
};

// std::max(0, dfs(...))
// return single arm not full path
// best init to INI_MIN
// post-order mandatory
// cache behavior
// one node
