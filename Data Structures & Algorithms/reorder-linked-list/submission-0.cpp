/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }

        ListNode* l1 = head;
        ListNode* l2 = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        l2 = slow->next;
        slow->next = nullptr;

        ListNode* curr = l2;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        l2 = prev;

        ListNode mergedList(0);
        ListNode* temp = &mergedList;
        int i = 1;

        while (l1 != nullptr && l2 != nullptr) {
            if (i % 2 == 1) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
            i++;
        }

        if (l1 == nullptr) {
            temp->next = l2;
        }
        else {
            temp->next = l1;
        }

        head = mergedList.next;
    }
};
