# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        dummy = head
        carry = 0
        while l1 != None and l2 != None:
            val1 = 0
            val2 = 0
            if l1 != None:
                val1 = l1.val
                l1 = l1.next
            if l2 != None:
                val2 = l2.val
                l2 = l2.next
            total = val1 + val2 + carry
            carry = total // 10
            dummy.next = ListNode(total % 10)
            dummy = dummy.next
        while l1 != None:
            total = l1.val + carry
            carry = total // 10
            dummy.next = ListNode(total % 10)
            dummy = dummy.next
            l1 = l1.next
        while l2 != None:
            total = l2.val + carry
            carry = total // 10
            dummy.next = ListNode(total % 10)
            dummy = dummy.next
            l2 = l2.next
        if carry != 0:
            dummy.next = ListNode(carry)
            dummy = dummy.next
        return head.next