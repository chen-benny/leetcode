#include <array>
#include <string>

using std::array; // array<Trie*, 26> is fixed size with no heap allocation
using std::string;

class Trie {
public:
    Trie(): next{}, is_end(false) {}

    void insert(const char* word) {
        Trie* node = this;
        for (const char* ch = word; *ch; ch++) {
            int idx = *ch - 'a';
            if (!node->next[idx]) { node->next[idx] = new Trie(); }
            node = node->next[idx];
        }
        node->is_end = true;
    }

    void insert(string word) { insert(word.c_str()); }

    bool search(const char* word) {
        const Trie* node = find(word);
        return node && node->is_end;
    }

    bool search(string word) { return search(word.c_str()); }

    bool startsWith(const char* prefix) { return find(prefix) != nullptr; }

    bool startsWith(string prefix) { return startsWith(prefix.c_str()); }

private:
    array<Trie*, 26> next;
    bool is_end;

    const Trie* find(const char* word) const {
        const Trie* node = this;
        for (const char* ch = word; *ch; ch++) {
            int idx = *ch - 'a';
            if (!node->next[idx]) { return nullptr; }
            node = node->next[idx];
        }
        return node;
    }
};
