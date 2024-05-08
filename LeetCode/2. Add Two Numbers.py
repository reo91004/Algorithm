from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        prev = None
        while cur:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        return prev

    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        l1 = self.reverseList(l1)
        l2 = self.reverseList(l2)
        res = ListNode()

        carry = 0

        while l1:
            sum = l1.val + l2.val + carry

            if sum >= 10:
                carry = sum // 10
            res.next = ListNode(sum)
            l1 = l1.next
            l2 = l2.next

        return res.next


s = Solution()
print(s.addTwoNumbers(l1=[2, 4, 3], l2=[5, 6, 4]))
