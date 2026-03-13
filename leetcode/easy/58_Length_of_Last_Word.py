class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # .isalpha() check english char
        i = -1
        while not s[i].isalpha():
            i-=1
        count = 1
        i-=1
        while -i <= len(s) and s[i].isalpha():
            count+=1
            i-=1
        return count