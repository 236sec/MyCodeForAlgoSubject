class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sorted_arr = sorted(set(arr))
        rank = {}
        cur_rank = 1
        for i in range(len(sorted_arr)):
            rank[sorted_arr[i]] = cur_rank
            cur_rank += 1
        for i in range(len(arr)):
            arr[i] = rank[arr[i]]
        return arr