class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int pos = 1; // Variable to track the current position in the list

        // Move curr to the node at position "left"
        while (curr != NULL && pos < left) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Perform the reversal within the sublist
        ListNode* sublistPrev = prev; // The node before the sublist
        ListNode* sublistEnd = curr;  // The last node of the sublist
        while (curr != NULL && pos <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        // Connect the sublist with the rest of the list
        if (sublistPrev != NULL) {
            sublistPrev->next = prev;
        } else {
            head = prev; // If left = 1, the head of the list needs to be updated
        }
        sublistEnd->next = curr;

        return head;
    }
};
