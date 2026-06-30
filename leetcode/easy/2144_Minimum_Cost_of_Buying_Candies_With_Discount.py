class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        if len(cost) <= 2:
            return sum(cost)
        cost.sort()
        ans = 0
        while cost:
            x = cost.pop()
            y = 0
            if cost:
                y = cost.pop()
            ans += x + y
            if cost:
                free = cost.pop()
        return ans
            