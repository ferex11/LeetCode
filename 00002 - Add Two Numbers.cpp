class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if (temp1) 
                sum += temp1->val;
            if (temp2) 
                sum += temp2->val;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            current->next = newNode;
            current = current->next;
            if (temp1) 
                temp1 = temp1->next; 
            if (temp2) 
                temp2 = temp2->next; 
        }
        if (carry) 
            current->next = new ListNode(carry);
        return dummyNode->next;
    }
};
