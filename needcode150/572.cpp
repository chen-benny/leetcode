// dfs, T: O(mn), S: O(h) stack frames

#include <cstddef>

class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) { return true; }
        if (!p || !q) { return false; }
        if (p->val != q->val) { return false; }
        return isSameTree(p->left, q->left) &
               isSameTree(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) { return false; }
        if (isSameTree(root, subRoot)) { return true; }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

// serialization + KMP, T: O(m + n), S: O(m + n)

#include <string>
#include <vector>
#include <cstddef>

class Solution {
private:
    void serialize(TreeNode* node, std::string& s) {
        if (!node) { s += "#$"; return; }
        s += "^" + std::to_string(node->val) + "$"; // prevent partial match, e.g. "12," and "2,"
        serialize(node->left, s);
        serialize(node->right, s);
    }

    std::vector<int> buildLPS(const std::string& pattern) {
        int n = static_cast<int>(pattern.size());
        std::vector<int> lps(n, 0);
        int len = 0, i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) { lps[i++] = ++len; }
            else if (len) { len = lps[len - 1]; }
            else { lps[i++] = 0; }
        }
        return lps;
    }

    bool kmpSearch(const std::string& text, const std::string& pattern) {
        std::vector<int> lps = buildLPS(pattern);
        int i = 0, j = 0;
        while (i < static_cast<int>(text.size())) {
            if (text[i] == pattern[j]) { ++i; ++j; }
            if (j == static_cast<int>(pattern.size())) { return true; }
            else if (i < static_cast<int>(text.size()) && text[i] != pattern[j] ) {
                if (j) { j = lps[j - 1]; }
                else { ++i; }
            }
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::string s, t;
        serialize(root, s);
        serialize(subRoot, t);
        return kmpSearch(s, t);
    }
};

// serialize with deilimters
// KMP vs native string match
// DFS win
// serialization overhead
// preorder serialization
// Rabin-Karp over KMP
