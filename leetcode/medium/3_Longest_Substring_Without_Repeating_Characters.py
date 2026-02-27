class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
      checkedChar = set()
      answer = 0
      left = 0
      for right in range(len(s)):
        if s[right] not in checkedChar:
          answer = max(answer,right-left+1)
          checkedChar.add(s[right])
        else:
          while s[right] in checkedChar:
            checkedChar.remove(s[left])
            left+=1
          checkedChar.add(s[right])
      return answer