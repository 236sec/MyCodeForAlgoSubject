class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverseArray(nums: List[int],start: int, end: int) -> None:
            nums[start:end] = reversed(nums[start:end])
        if k == 0 or k == len(nums):
            return
        newK = k % len(nums)
        left = 0
        endLeft = len(nums) - newK
        right = len(nums) - newK
        endRight = len(nums)
        reverseArray(nums,left,endLeft)
        reverseArray(nums,right,endRight)
        reverseArray(nums,0,len(nums))
        return