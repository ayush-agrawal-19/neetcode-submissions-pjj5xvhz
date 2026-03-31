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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_order;
        
        if (!root) return level_order;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> node_val;
            vector<TreeNode*> nodes;

            while (!q.empty()) {
                nodes.push_back(q.front());;
                q.pop();
            }

            for (TreeNode* node : nodes) {
                if (!node) continue;
                node_val.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }

            if (!node_val.empty()) level_order.push_back(node_val);
        }

        return level_order;
    }
};
