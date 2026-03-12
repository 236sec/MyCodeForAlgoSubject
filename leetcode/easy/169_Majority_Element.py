class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        numToCount = {}
        for num in nums:
            if num in numToCount:
                numToCount[num] += 1
            else:
                numToCount[num] = 1
        maxKey = 0
        maxCount = 0
        for key,value in numToCount.items():
            if value > maxCount:
                maxKey = key
                maxCount = value
        return maxKey