class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        total = 8
        start = 12
        digit = 3
        while start <= high:
            tmp = start
            for i in range(total):
                if start >= low and start <= high:
                    ans.append(start)
                n = 10 - total
                start = (start * 10 + digit) % 10**n
                digit+=1
            tmp2 = 10 - total + 1
            total -= 1
            start = tmp * 10 + (tmp2)
            digit = tmp2 + 1
        return ans