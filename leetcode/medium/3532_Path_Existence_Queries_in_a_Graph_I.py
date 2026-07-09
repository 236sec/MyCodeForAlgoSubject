class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        group = {}
        curgroup = 1
        recent = nums[0]
        group[0] = curgroup
        for i in range(1,len(nums)):
            if nums[i]-recent > maxDiff:
                curgroup+=1
            group[i] = curgroup
            recent = nums[i]
        ans = [False] * len(queries)
        for i in range(len(queries)):
            x = queries[i][0]
            y = queries[i][1]
            if group[x] == group[y]:
                ans[i] = True
        return ans
