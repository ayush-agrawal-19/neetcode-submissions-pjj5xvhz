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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        for (int i=0; i<inorder.size(); i++) {
            inorder_index[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder.size() - 1);
    }
    
    unordered_map<int, int> inorder_index;
    int preorder_index = 0;

    TreeNode* dfs(vector<int> preorder, int l, int r) {
        if (l > r) return nullptr;

        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);

        int mid = inorder_index[root_val];

        root->left = dfs(preorder, l, mid-1);
        root->right = dfs(preorder, mid+1, r);

        return root;
    }
};
