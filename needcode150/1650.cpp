// hash set of ancestors, T: O(h), S: O(h)

#include <unordered_set>
#include <cstddef>

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        std::unordered_set<Node*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = p->parent;
        }
        while (q) {
            if (ancestors.count(q)) { return q; }
            q = q->parent;
        }
        return nullptr;
    }
};

// two pointers, :T O(h), S: O(1)

#include <cstddef>

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* n1 = p;
        Node* n2 = q;

        while (n1 != n2) {
            n1 = n1 ? n1->parent : q;
            n2 = n2 ? n2->parent : p;
        }
        return n1;
    }
};
