class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numToIndex = {}
        for i,num in enumerate(nums):
            want = target - num
            if want in numToIndex:
                return [i,numToIndex[want]]
            numToIndex[num] = i
        return []
