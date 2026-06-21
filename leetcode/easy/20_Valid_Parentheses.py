class Solution:
    def isValid(self, s: str) -> bool:
        stack = [s[0]]
        pair_brackets = {
            ']': '[',
            ')':'(',
            '}':'{',
        }
        i = 1
        while i < len(s):
            if s[i] in pair_brackets.values():
                stack.append(s[i])
            elif s[i] in pair_brackets.keys() and len(stack) > 0:
                checked = stack.pop()
                if pair_brackets[s[i]] == checked:
                    i+=1
                    continue
                else:
                    return False
            else:
                return False
            i += 1
        if len(stack) > 0:
            return False
        return True
