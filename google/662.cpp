// bfs with index encoding, T: O(n), S: O(w)

#include <vector>
#include <queue>
#include <cstddef>
#include <algorithm>
#include <utility>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) { return 0; }

        std::queue<std::pair<TreeNode*, unsigned long long>> q; // {node, idx}
        q.push({root, 0ULL});
        int maxWidth = 0;

        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            unsigned long long left = q.front().second;
            unsigned long long right = 0;

            for (int i = 0; i < sz; ++i) {
                auto [node, idx] = q.front();
                q.pop();
                right = idx;

                // normalize index to prevent overflow
                unsigned long long norm = idx - left;
                if (node->left) { q.push({node->left, 2 * norm + 1}); }
                if (node->right) { q.push({node->right, 2 * norm + 2}); }
            }
            maxWidth = std::max(maxWidth, static_cast<int>(right - left + 1)); 
        }
        return maxWidth;
    }
};

// unsigned long long for indices: full binary-tree has indices up to 2^h
// normalization: left-base to prevent exponentail growth, 1ULL seed root at 0, 2*i and 2*i+1 for left and right
