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
    int ans = 0;
public:
    pair<int,int> average(TreeNode* root, int curr, int count){
        if(root == NULL) 
            return {0,0};
        pair<int,int> left = average(root -> left, curr, count);
        pair<int,int> right = average(root -> right, curr, count);
        curr += root -> val + left.first + right.first;
        count += left.second + right.second + 1;
        if((curr/count) == root -> val) 
            ans++;
        return {curr, count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        average(root, 0, 0);
        return ans;
    }
};







