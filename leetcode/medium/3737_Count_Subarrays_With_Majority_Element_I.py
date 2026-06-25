class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        ans = 0
        for i in range(len(nums)):
            counting = 0
            for j in range(len(nums)-i):
                if nums[i+j] == target:
                    counting += 1
                else:
                    counting -= 1
                if counting > 0:
                    ans += 1
        return ans