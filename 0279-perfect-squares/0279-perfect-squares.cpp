class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;

        for(int target=1;target<=n;target++){
            for(int i=1;i*i<=target;i++){
                int square=i*i;

                dp[target]=min(dp[target],1+dp[target-square]);
            }
        }
        return dp[n];
    }
};