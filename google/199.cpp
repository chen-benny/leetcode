// bfs, T: O(n), S: O(w)

#include <vector>
#include <queue>
#include <cstddef> // nullptr

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
                TreeNode* curr = q.front();
                q.pop();
                if (i == sz - 1) { out.push_back(curr->val); }
                if (curr->left) { q.push(curr->left); }
                if (curr->right) { q.push(curr->right); }
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

// dfs right-before-left, bfs i==size-1
// cache bfs vs dfs: spatially local for top-down allocated tree vs right-heavy tree cache-warm
