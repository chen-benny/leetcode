#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int target;
    int count = 0;
    std::unordered_map<long long, int> freq;

    void dfs(TreeNode* node, long long preSum) {
        if (!node) { return; }

        preSum += node->val;

        auto comp = freq.find(preSum - target);
        if (comp != freq.end()) { count += comp->second; }

        ++freq[preSum];
        dfs(node->left, preSum);
        dfs(node->right, preSum);
        --freq[preSum];
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        freq.reserve(1024);
        freq[0] = 1; // empty prefix handles paths starting from root
        dfs(root, 0LL);
        return count;
    }
};
