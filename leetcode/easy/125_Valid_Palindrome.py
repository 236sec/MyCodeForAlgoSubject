class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        isValid = True
        while j > i:
            if not s[i].isalnum():
                i+=1
                continue
            if not s[j].isalnum():
                j-=1
                continue
            if s[i].lower() == s[j].lower():
                i+=1
                j-=1
            else:
                isValid = False
                break
        return isValid