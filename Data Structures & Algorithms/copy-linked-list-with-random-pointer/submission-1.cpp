/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* curr = head;
        unordered_map<Node*, Node*> copy_map;
        Node dummy(0);

        while (curr != nullptr) {
            copy_map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr) {
                copy_map[curr]->next = copy_map[curr->next];
            }
            else {
                copy_map[curr]->next = nullptr;
            }

            if (curr->random != nullptr) {
                copy_map[curr]->random = copy_map[curr->random];
            }
            else {
                copy_map[curr]->random = nullptr;
            }

            curr = curr->next;
        }

        return copy_map[head];
    }
};
