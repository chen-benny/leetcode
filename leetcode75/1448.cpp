#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    static void dfs(TreeNode* node, int curMax, int& count) {
        if (!node) { return; }

        if (node->val >= curMax) {
            ++count;
            curMax = node->val;
        }

        dfs(node->left, curMax, count);
        dfs(node->right, curMax, count);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }
};

// follow-up: stack

#include <utility>

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) { return 0; }

        static std::pair<TreeNode*, int> stk[10001];
        int top = 0;
        int count = 0;

        stk[top++] = {root, INT_MIN};

        while (top > 0) {
            auto [node, curMax] = stk[--top];

            if (node->val >= curMax) {
                ++count;
                curMax = node->val;
            }

            if (node->right) { stk[top++] = {node->right, curMax}; }
            if (node->left) { stk[top++] = {node->left, curMax}; }
        }

        return count;
    }
};
