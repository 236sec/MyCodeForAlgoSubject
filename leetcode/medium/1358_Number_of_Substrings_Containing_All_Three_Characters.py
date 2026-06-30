class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        p = {'a':0,'b':0,'c':0}
        l = 0
        r = 0
        ans = 0
        while True:
            if p['a'] > 0 and p['b'] > 0 and p['c'] > 0:
                ans = ans + 1 + len(s) - r
                p[s[l]] -= 1
                l += 1
            else:
                if r == len(s):
                    break
                p[s[r]] += 1
                r += 1
        return ans