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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* curr = head;
        int count = 0;

        // Check if k nodes are available
        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }

        // Fewer than k nodes -> leave them unchanged
        if (count < k)
            return head;

        // Reverse first k nodes
        ListNode* prev = NULL;
        curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // head is now the last node of reversed group
        head->next = reverseKGroup(curr, k);

        // prev is the new head of this group
        return prev;
    }
};