class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=1)
        maxValue = 0
        for i in range(len(citations)):
            if citations[i] >= i+1:
                maxValue = i+1
        return maxValue