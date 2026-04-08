// bst property traversal, T: O(h), S: O(1) iterative

#include <cstddef>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr) {
            if (p->val < curr->val && q->val < curr->val) { curr = curr->left; }
            else if (p->val > curr->val && q->val > curr->val) { curr = curr->right; }
            else { return curr; }
        }
        return nullptr;
    }
};

// recursive, T: O(h), S: O(h) stack frames

#include <cstddef>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

// O(1) space
// else { return curr }
// O(h) not O(logn)
// branch prediction
// cache behavior
// curr == p return curr
// recursive tail recursion optmization
