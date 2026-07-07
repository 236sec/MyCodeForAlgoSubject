class Solution:
    def sumAndMultiply(self, n: int) -> int:
        total = 0
        ans = 0
        degree = 0
        while n > 0:
            num = n % 10
            n = n // 10
            if num != 0:
                total += num
                ans = num * 10**degree + ans
                degree+=1
        return ans * total