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
    void solve(TreeNode* root,int mini,long long &ans){
        if(root==NULL){
            return;
        }
        if(root->val>mini){
            ans=min(ans,(long long)root->val);
            return;
        }
        solve(root->left,mini,ans);
        solve(root->right,mini,ans);
        
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mini=root->val;
        long long ans =LLONG_MAX;
        solve(root,mini,ans);
        if(ans==LLONG_MAX){
            return -1;
        }
        return ans;
    }
};