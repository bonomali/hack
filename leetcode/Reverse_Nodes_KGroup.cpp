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
    ListNode *reverseK(ListNode *head, int k){
        if (head == NULL) return NULL;
        //if (k == 1) return head;
        ListNode *prev =NULL;
        ListNode *cur =head;
        ListNode *next =NULL;
        while (k > 0){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            k--;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 0 || head == NULL) return head;
        ListNode* runner = head;
        for(int i = 0; i < k; i++){
            runner = runner->next;
            if (runner == NULL && i < k - 1) return head;
        }
        head = reverseK(head, k);
        ListNode* newP = head;
        for (int i = 1; i < k; i++){
            newP = newP->next;
        }
        newP->next = reverseKGroup(runner, k);
        return head;
    }
};
