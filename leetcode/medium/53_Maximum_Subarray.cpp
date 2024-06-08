class Solution {
public:
    int memo[100010];

    int opt(int n,vector<int> &v) {
        if(n<=1) {
            return v[0];
        }
        if(memo[n] != -1) {
            return memo[n];
        }
        int ans = max({opt(n-1,v)+v[n-1],v[n-1]});
        memo[n] = ans;
        return memo[n];
    }

    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int size = nums.size();
        memset(memo,-1,sizeof(memo));
        for(int i = 2 ; i <= size ; i++) {
            max_sum = max(max_sum,opt(i,nums));
        }
        return max_sum;
    }
};