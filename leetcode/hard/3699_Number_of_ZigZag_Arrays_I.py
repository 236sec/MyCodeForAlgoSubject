class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m= r - l + 1
        dp = [1] * m

        for i in range(2,n+1):
            prev = 0
            if i % 2 == 0:
                for j in range(m):
                    tmp = dp[j]
                    dp[j] = prev
                    if j != m-1:
                        prev+=tmp
            else:
                for j in range(m-1,-1,-1):
                    tmp = dp[j]
                    dp[j] = prev
                    if j != 0:
                        prev+=tmp
        return (2*sum(dp))%MOD
