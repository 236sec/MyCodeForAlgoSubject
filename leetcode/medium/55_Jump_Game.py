class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump = 0
        i=0
        while i <= maxJump and i < len(nums):
            maxJump = max(i + nums[i],maxJump)
            i+=1
        if i >= len(nums):
            return True
        return False