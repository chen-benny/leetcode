#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxLen = 0;

    // dir: 0 = come from left, 1 = come from right
    void dfs(TreeNode* node, int dir, int len) {
        if (!node) { return; }

        if (len > maxLen) { maxLen = len; }

        if (dir == 0) {
            dfs(node->left, 1, len + 1);
            dfs(node->right, 0, 1);
        } else {
            dfs(node->right, 0, len + 1);
            dfs(node->left, 1, 1);
        }

    }

public:
    int longestZigZag(TreeNode* root) {
        if (!root) { return 0; }
        dfs(root->left, 1, 1);
        dfs(root->right, 0, 1);
        return maxLen;
    }
};

// follow-up: pass both dir simul, halve the recursive calls

class Solution {
    int maxLen = 0;

    // leftLen, rightLen: zigzag len if arrived left / right
    void dfs(TreeNode* node, int leftLen, int rightLen) {
        if (!node) { return; }

        int curMax = std::max(leftLen, rightLen);
        if (curMax > maxLen) { maxLen = curMax; }

        dfs(node->left, rightLen + 1, 0);
        dfs(node->right, 0, leftLen + 1);
    }


public:
    int longestZigZag(TreeNode* root) {
        if (!root) { return 0; }
        dfs(root, 0, 0);
        return maxLen;
    }
};
