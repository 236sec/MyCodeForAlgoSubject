class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] =max(dp[i],dp[j]+1);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] > ans){
            ans = dp[i];
            }
        }
        return ans;
    }
};
