class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        index = 0
        tmp = 100000
        for i,num in enumerate(nums):
            if num != tmp:
                nums[index] = num
                if i+1 < len(nums) and nums[i+1] == num:
                    nums[index+1] = num
                    index+=2
                    tmp = num
                else:
                    index+=1
        return index