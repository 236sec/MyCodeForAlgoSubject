class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        cache = dict()
        def rec(i, j):
            ans = False
            if (i,j) in cache:
                return cache[(i,j)]
            if j == len(p):
                return i == len(s)
            match = i < len(s) and (s[i] == p[j] or p[j] == '.')
            if j < len(p)-1 and p[j+1] == '*':
                ans = rec(i,j+2) or (match and rec(i+1,j))
            else:
                ans = match and rec(i+1,j+1)
            cache[(i,j)] = ans
            return ans
        return rec(0, 0)
