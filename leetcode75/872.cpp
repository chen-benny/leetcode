#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    static void collectLeaves(TreeNode* node, vector<int>& leaves) {
        if (!node) {
            return;
        }

        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return;
        }

        collectLeaves(node->left, leaves);
        collectLeaves(node->right, leaves);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        leaves1.reserve(256);
        leaves2.reserve(256);

        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }
};

// follow-up: no vector, compare on the fly

class Solution {
    // Iterator of next leaf, on static stack
    struct LeafIter {
        TreeNode* stk[256];
        int top = 0;

        explicit LeafIter(TreeNode* root) {
            if (root) {
                stk[top++] = root;
            }
        }
        // Returns next leaf or nullptr if exhausted
        TreeNode* next() {
            while (top > 0) {
                TreeNode* node = stk[--top];
                if (!node->left && !node->right) {
                    return node;
                }

                if (node->right) {
                    stk[top++] = node->right;
                }
                if (node->left) {
                    stk[top++] = node->left;
                }
            }
            return nullptr;
        }
    };

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        LeafIter iter1(root1), iter2(root2);

        while (true) {
            TreeNode* leaf1 = iter1.next();
            TreeNode* leaf2 = iter2.next();

            if (!leaf1 && !leaf2) {
                return true;
            }
            if (!leaf1 || !leaf2) {
                return false;
            }
            if (leaf1->val != leaf2->val) {
                return false;
            }
        }
    }
};
