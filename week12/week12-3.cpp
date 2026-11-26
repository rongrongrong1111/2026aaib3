/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(999); // 上週教的工具1
        ListNode* now = ans; // 上週教的工具2
        int carry = 0; // 進位，week12重點

        // 老師的版本，只要還有剩下一條，就繼續迴圈
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) carry += l1->val; // 如果 l1 還有，就把 val 加進去
            if (l2 != nullptr) carry += l2->val; // 如果 l2 還有，就把 val 加進去

            now->next = new ListNode(carry % 10);
            carry = carry / 10; // 進位，week12重點
            now = now->next;

            if (l1 != nullptr) l1 = l1->next; // 如果還有，才繼續下一筆
            if (l2 != nullptr) l2 = l2->next;
        }
        if(carry) now->next = new ListNode(carry);
        return ans->next;
    }
};
