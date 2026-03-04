class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) { return nullptr; }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) { return root->right; }
            if (!root->right) { return root->left; }

            // two children: replace val with inorder successor, then delete successor
            TreeNode* succ = inorderSuccessor(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }

private:
    TreeNode* inorderSuccessor(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
