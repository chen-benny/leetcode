// recursive + hash-map, T: O(n), S: O(n)

#include <vector>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> inIdx; // val -> idx in inorder
    int preIdx = 0; // class member avoid reference threading

    TreeNode* build(std::vector<int>& preorder, int inLeft, int inRight) {
        if (inLeft > inRight) { return nullptr; }
        int rootVal = preorder[preIdx++];

        TreeNode* root = new TreeNode(rootVal);
        int mid = inIdx[rootVal];
        root->left = build(preorder, inLeft, mid - 1);
        root->right = build(preorder, mid + 1, inRight);
        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inIdx[inorder[i]] = i;
        }
        return build(preorder, 0, static_cast<int>(inorder.size()) - 1);
    }
};

// hash-map > flat-array
// preIdx as member
// left subtree first
// new TreeNode heap allocation
// cache behavior
// inLeft > inRight over inLeft == inRight
