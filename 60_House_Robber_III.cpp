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
    int solve(map<TreeNode*, int>& m, TreeNode* root){
        if(!root)
            return 0;
        int ans=root->val;
        if(m.find(root)!=m.end())
            return m[root];
        if(root->left)
            ans+=solve(m, root->left->left)+solve(m, root->left->right);   
        if(root->right)
            ans+=solve(m,root->right->left)+solve(m, root->right->right);
        return m[root]=max(ans, solve(m,root->left)+solve(m, root->right));
    }
    int rob(TreeNode* root) {
        map<TreeNode*, int>m;
        return solve(m, root);
    }
};
