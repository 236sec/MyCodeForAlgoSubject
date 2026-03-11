class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = len(nums) -1
        while j >= i:
            if nums[i] == val:
                while nums[j] == val and j > i:
                    j-=1
                if j > i and nums[j] != val:
                    nums[i] = nums[j]
                    j-=1
                elif j <= i:
                    break
            i+=1
        return i