class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        rfreq = {}
        for num in nums:
            if num == 1:
                continue
            if num in rfreq:
                rfreq[num] += 1
            else:
                rfreq[num] = 1
        skipped = {}
        ans = 1
        for num in nums:
            if num == 1:
                continue
            if num in skipped:
                continue
            tmpans = 1
            sqValue = isqrt(num)
            if sqValue * sqValue != num:
                continue
            while True:
                if sqValue in rfreq and rfreq[sqValue] >= 2:
                    tmpans += 2
                    skipped[num] = 1
                else:
                    break
                last = sqValue
                sqValue = isqrt(sqValue)
                if sqValue <= 1 or sqValue * sqValue != last:
                    break
            ans = max(tmpans,ans)
        totalOne = nums.count(1)
        if totalOne%2 == 0:
            ans = max(totalOne-1,ans)
        else:
            ans = max(totalOne,ans)
        return ans