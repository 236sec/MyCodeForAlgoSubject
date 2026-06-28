class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1],[1,1]]
        ans = [[1],[1,1]]
        for i in range(numRows-2):
            cur = [1]
            length = len(ans[-1])
            for j in range(length-1):
                x = ans[-1][j]
                y = ans[-1][j+1]
                cur.append(x+y)
            cur.append(1)
            ans.append(cur)
        return ans
