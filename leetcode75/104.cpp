#include <algorithm>
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

// follow-up: stack

#include <cstdlib>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        static std::pair<TreeNode*, int> stk[10001]; // pre-allocated
        int top = 0;
        int maxDepth = 0;

        stk[top++] = {root, 1};

        while (top > 0) {
            auto [node, depth] = stk[--top];
            if (depth > maxDepth) {
                maxDepth = depth;
            }

            if (node->right) {
                stk[top++] = {node->right, depth + 1};
            }
            if (node->left) {
                stk[top++] = {node->left, depth + 1};
            }
        }

        return maxDepth;
    }
};
