/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return addWithCarry(l1, l2, 0);
    }
    
    ListNode* addWithCarry(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == NULL && l2 == NULL && carry == 0)   return NULL;
        int value = carry;
        if (l1)    value += l1->val;
        if (l2)    value += l2->val;
        ListNode* result = new ListNode(value%10);
        result->next = addWithCarry(l1 == NULL ? NULL : l1->next,
                                    l2 == NULL ? NULL : l2->next,
                                    value > 9 ? 1 : 0);
        return result;
    }
};
