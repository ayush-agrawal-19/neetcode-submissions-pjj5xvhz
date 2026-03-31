/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr && q != nullptr) {
            return false;
        }
        if (p != nullptr && q == nullptr) {
            return false;
        }

        bool left;
        bool right;

        if (p->val == q->val) {
            left = isSameTree(p->left, q->left);
        }
        else {
            return false;
        }
        
        if (p->val == q->val) {
            right = isSameTree(p->right, q->right);
        }
        else {
            return false;
        }

        if (left && right) {
            return true;
        }
        else {
            return false;
        }
    }
};
