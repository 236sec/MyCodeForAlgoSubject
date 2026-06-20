class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }
        i = 0
        j = 1
        ans = 0
        while (j < len(s)):
            val1 = roman[s[i]]
            val2 = roman[s[j]]
            if val1 >= val2:
                ans += val1
            else:
                ans -= val1
            i+=1
            j+=1
        return ans + roman[s[-1]]
