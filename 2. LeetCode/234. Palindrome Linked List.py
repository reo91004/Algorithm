from collections import deque


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:  # head가 비어있다면
            return True

        queue = deque()
        # head가 빌 때까지 queue에 삽입
        while head is not None:
            queue.append(head.val)
            head = head.next

        # 양쪽 끝으로 판별
        length = len(queue)
        for i in range(length // 2):
            if queue[i] != queue[length - 1 - i]:
                return False
        return True
