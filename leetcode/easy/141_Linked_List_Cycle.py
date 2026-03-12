# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        dummy = head
        foundValue = 100001
        while dummy != None:
            if dummy.val != foundValue:
                dummy.val = foundValue
            else:
                return True
            dummy = dummy.next
        return False