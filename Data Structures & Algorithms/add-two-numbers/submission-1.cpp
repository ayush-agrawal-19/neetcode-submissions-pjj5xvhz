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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* next_int = &dummy;
        ListNode* l1_iter = l1;
        ListNode* l2_iter = l2;
        int carry = 0;

        while (l1_iter != nullptr || l2_iter != nullptr || carry != 0) {
            int sum = carry;

            if (l1_iter != nullptr) {
                sum += l1_iter->val;
                l1_iter = l1_iter->next;
            }

            if (l2_iter != nullptr) {
                sum += l2_iter->val;
                l2_iter = l2_iter->next;
            }

            carry = sum / 10;

            next_int->next = new ListNode(sum % 10);
            next_int = next_int->next;
        }

        return dummy.next;
    }
};
