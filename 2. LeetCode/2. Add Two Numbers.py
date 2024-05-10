from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        res = ListNode(0)  # dummy node로 시작
        cur = res

        carry = 0

        while (
            l1 or l2 or carry
        ):  # l1, l2 둘 중 하나라도 남아 있거나, carry가 있는 경우 계속 실행
            sum = carry
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next

            carry = sum // 10
            cur.next = ListNode(sum % 10)  # 새 노드 생성 후 결과 연결
            cur = cur.next

        return res.next


s = Solution()
print(s.addTwoNumbers(l1=[2, 4, 3], l2=[5, 6, 4]))
