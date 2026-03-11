class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        index = 0
        tmp = -101
        for num in nums:
            if num != tmp:
                nums[index] = num
                index+=1
                tmp = num
        return index
            