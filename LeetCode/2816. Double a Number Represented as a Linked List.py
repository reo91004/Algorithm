from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        cur = head
        while cur:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        return prev

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        # 연결리스트 뒤집기
        head = self.reverseList(head)
        cur = head
        carry = 0

        # 각 노드의 값을 두 배로 만듭니다.
        while cur:
            doubled_value = cur.val * 2 + carry
            cur.val = doubled_value % 10
            carry = doubled_value // 10
            # carry가 남아 있는데 노드가 끝이면 하나 추가
            if not cur.next and carry:
                cur.next = ListNode(carry)
                break
            cur = cur.next

        # 다시 뒤집기
        return self.reverseList(head)


s = Solution()
print(s.doubleIt([1, 8, 9]))
