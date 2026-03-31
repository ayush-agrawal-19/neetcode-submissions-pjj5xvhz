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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        dfs(root);

        return values[k];
    }

    vector<int> values;

    TreeNode* dfs(TreeNode* root) {
        if (!root) return root;
        
        TreeNode* node;

        if (root->left) {
            node = dfs(root->left);
        }

        if (find(values.begin(), values.end(), node->val) == values.end()){
            values.push_back(node->val);
        }

        if (find(values.begin(), values.end(), root->val) == values.end()){
            values.push_back(root->val);
        }

        if (root->right) {
            node = dfs(root->right);
        }

        if (find(values.begin(), values.end(), node->val) == values.end()){
            values.push_back(node->val);
        }

        return root;
    }
};
