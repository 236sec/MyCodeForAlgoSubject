class Solution:
    def maxProduct(self, n: int) -> int:
        max1 = 0
        max2 = 0
        while n > 0:
            d = n % 10
            n = n // 10
            if d >= max1:
                max2 = max1
                max1 = d
            elif d > max2:
                max2 = d
        return max1*max2