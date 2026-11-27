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
    TreeNode* construct(vector<int>& nums,int left,int right){
        if(left>right){
            return nullptr;
        }
        int maxIdx=left;
        for(int i=left;i<=right;i++){
            if(nums[i]>nums[maxIdx]){
                maxIdx=i;
            }
        }
        TreeNode* root=new TreeNode(nums[maxIdx]);
        root->left=construct(nums,left,maxIdx-1);
        root->right=construct(nums,maxIdx+1,right);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};