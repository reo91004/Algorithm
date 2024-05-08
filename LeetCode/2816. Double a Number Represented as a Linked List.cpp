class Solution {
public:
    // 리스트 뒤집기 함수
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    // 리스트 두 배로 만들기 함수
    ListNode *doubleIt(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        // 리스트 뒤집기
        head = reverseList(head);
        ListNode *cur = head;
        int carry = 0;

        // 노드를 순회하면서 값을 두 배로 만들기
        while (cur != nullptr) {
            int doubled_value = cur->val * 2 + carry;
            cur->val = doubled_value % 10;
            carry = doubled_value / 10;

            // 마지막 노드이고 캐리가 남아있다면 새 노드 추가
            if (cur->next == nullptr && carry) {
                cur->next = new ListNode(carry);
                break;
            }
            cur = cur->next;
        }

        // 다시 리스트를 뒤집어 원래 순서로 복구
        return reverseList(head);
    }
};