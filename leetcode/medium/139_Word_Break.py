class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo = [-1] * len(s)
        def wordplace(s:str,wordDict: List[str],j:int) -> bool:
            if j == len(s):
                return True
            if j > len(s):
                return False
            if memo[j] != -1:
                if memo[j] == 1:
                    return True
                return False
            result = False
            for word in wordDict:
                if j+len(word) <= len(s) and word == s[j:j+len(word)]:
                    result = result or wordplace(s,wordDict,j+len(word))
            if result:
                memo[j] = True
            else:
                memo[j] = False
            return result
        return wordplace(s,wordDict,0)