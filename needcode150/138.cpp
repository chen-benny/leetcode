// hahs-map, T: O(n), S: O(n)

#include <unordered_map>
#include <cstddef>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) { return nullptr; }

        std::unordered_map<Node*, Node*> map;
        map.reserve(256);
        map.max_load_factor(0.25f);

        Node* curr = head;
        while (curr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};

// interleaving, T: O(n), S: O(1)

#include <cstddef>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) { return nullptr; }
        
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node dummy(0);
        Node* tail = &dummy;
        curr = head;
        while (curr) {
            tail->next = curr->next;
            tail = tail->next;
            curr->next = tail->next;
            curr = curr->next;
        }

        return dummy.next;
    }
};

/*
   - interleaving for random
   - hash-map pointer keys
   - new Node on hot path
   - cache behavior
   ? map[curr->next], map[curr->random] work for nullptr
   ? interleaving restore the original list
*/
