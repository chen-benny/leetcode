// bfs level order, T: O(n), S: O(w), w = max width

#include <vector>
#include <queue>
#include <cstddef>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> out;
        if (!root) { return out; }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (i == sz - 1) { out.push_back(node->val); }
                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
        }
        return out;
    }
};

// dfs, T: O(n), S: O(h)

#include <vector>
#include <cstddef>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> out;
        dfs(root, 0, out);
        return out;
    }

private:
    void dfs(TreeNode* node, int depth, std::vector<int>& out) {
        if (!node) { return; }
        if (depth == static_cast<int>(out.size())) { out.push_back(node->val); }
        dfs(node->right, depth + 1, out);
        dfs(node->left, depth + 1, out);
    }
};

// dfs right-before-left
// bfs i == sz -1
// bfs vs dfs
// cache behavior
// left-heavy tree
