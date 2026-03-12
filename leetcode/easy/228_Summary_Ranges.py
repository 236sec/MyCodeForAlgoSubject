class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums)==0:
            return []
        startNum = nums[0]
        output = list()
        for i in range(1,len(nums)):
            if nums[i] - 1 == nums[i-1]:
                continue
            else:
                if startNum == nums[i-1]:
                    output.append(f"{startNum}")
                else:
                    output.append(f"{startNum}->{nums[i-1]}")
                startNum = nums[i]
        if startNum == nums[len(nums)-1]:
            output.append(f"{startNum}")
        else:
            output.append(f"{startNum}->{nums[len(nums)-1]}")
        return output