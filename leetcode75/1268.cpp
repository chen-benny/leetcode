#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::sort;
using std::lower_bound;
using std::min;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        constexpr int MAX_CAND = 3;
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        res.reserve(searchWord.size());
        string prefix;

        for (char ch : searchWord) {
            prefix += ch;
            auto pos = lower_bound(products.begin(), products.end(), prefix);

            vector<string> matches;
            for (int i = 0; i < MAX_CAND && pos + i != products.end(); i++) {
                const string& cand = *(pos + i);
                if (cand.compare(0, prefix.size(), prefix) == 0) {
                    matches.push_back(cand);
                }
            }

            res.push_back(std::move(matches));
        }

        return res;
    }
};

// follow-up: trie

#include <array>

using std::array;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for (const string& word : products) { insert(word); }

        vector<vector<string>> res;
        res.reserve(searchWord.size());
        Node* node = &root;

        for (char ch : searchWord) {
            int idx = ch - 'a';
            if (node) { node = node->next[idx]; }

            vector<string> matches;
            if (node) { collect(node, matches); }
            res.push_back(std::move(matches));
        }

        return res;
    }

private:
    struct Node {
        array<Node*, 26> next{};
        const string* word = nullptr;
    };

    static constexpr int MAX_NODES = 20001;
    Node pool[MAX_NODES];
    int cnt = 0;
    Node root;

    Node* new_node() { return &pool[cnt++]; }

    void insert(const string& word) {
        Node* node = &root;
        for (const char* ch = word.c_str(); *ch; ch++) {
            int idx = *ch - 'a';
            if (!node->next[idx]) { node->next[idx] = new_node(); }
            node = node->next[idx];
        }
        node->word = &word;
    }

    void collect(const Node* node, vector<string>& matches) {
        if (matches.size() == 3) { return; }
        if (node->word) { matches.push_back(*(node->word)); }

        for (int i = 0; i < 26; i++) {
            if (node->next[i]) {
                collect(node->next[i], matches);
                if (matches.size() == 3) { return; }
            }
        }
    }
};
