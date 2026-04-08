// preorder dfs, T: O(n), S: O(n)

#include <string>
#include <sstream>
#include <cstddef>

class Codec {
private:
    void serializer(TreeNode* node, std::string& s) {
        if (!node) { s += "#$"; return; }
        s += "^" + std::to_string(node->val) + "$"; 
        serializer(node->left, s);
        serializer(node->right, s);
    }

    TreeNode* deserializer(std::istringstream& ss) {
        std::string token;
        std::getline(ss, token, '$');
        if (token == "#") { return nullptr; }
        TreeNode* node = new TreeNode(std::stoi(token.substr(1))); // skip '^'
        node->left = deserializer(ss);
        node->right = deserializer(ss);
        return node;
    }

public:
    std::string serialize(TreeNode* root) {
        std::string s;
        serializer(root, s);
        return s;
    }

    TreeNode* deserialize(std::string data) {
        std::istringstream ss(data);
        return deserializer(ss);
    }
};

// std::istreamstring
// preorder
// string construct overhead
// std::stoi hot path
// cache behavior
// "," as delimiter over " "
// bfs serialization
