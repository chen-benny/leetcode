// bfs with direction flag, T: O(n), S: O(w), w = max width

#include <vector>
#include <queue>
#include <cstddef> // nullptr

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> out;
        if (!root) { return out; }

        std::queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // level-0 at root is leftToRight
        std::vector<int> level;

        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            level.resize(sz);

            for (int i = 0; i < sz; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                int idx = leftToRight ? i : sz - 1 - i;
                level[idx] = curr->val;
                if (curr->left) { q.push(curr->left); }
                if (curr->right) { q.push(curr->right); }
            }
            out.push_back(std::move(level));
            leftToRight = !leftToRight;
        }
        return out;
    }
};

// direct index placement over reverse: O(1) index computation vs O(w) reversal per level
// pre-allocated level with std::move and resize
// bfs over dfs for zigzag: dfs suffers from not-knowing level size, reverse or two-pass
