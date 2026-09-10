class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxDP=nums[0];
        int minDP=nums[0];

        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            int a=curr;
            int b=curr*maxDP;
            int c=curr*minDP;

            int newMax=max(a,max(b,c));
            int newMin=min(a,min(b,c));

            maxDP=newMax;
            minDP=newMin;

            ans=max(ans,maxDP);
        }
        return ans;
    }
};