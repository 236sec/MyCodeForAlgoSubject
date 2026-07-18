class Solution:
    def findGCD(self, nums: List[int]) -> int:
        min_num = inf
        max_num = -inf
        for num in nums:
            if num > max_num:
                max_num = num
            if num < min_num:
                min_num = num
        return math.gcd(min_num,max_num)