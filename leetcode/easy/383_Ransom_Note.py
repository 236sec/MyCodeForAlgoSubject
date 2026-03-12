class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        charToCount = {}
        for char in magazine:
            if char in charToCount:
                charToCount[char] += 1
            else:
                charToCount[char] = 1
        for char in ransomNote:
            if char in charToCount and charToCount[char] > 0:
                charToCount[char] -= 1
            else:
                return False
        return True