class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [10001] * n
        dp[n-1] = 0
        for i in range(n-2,-1,-1):
            for j in range(0,nums[i]+1):
                if i+j <= n-1:
                    dp[i] = min(dp[i],1+dp[i+j])
        return dp[0]