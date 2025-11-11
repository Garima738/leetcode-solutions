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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count length
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // If we need to remove head itself
        if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 2: Find node before the one we want to delete
        int pos = length - n;  // index of node to delete
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Step 3: Delete the node
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};

        
 