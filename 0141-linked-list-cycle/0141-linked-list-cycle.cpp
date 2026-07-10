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
    bool hasCycle(ListNode *head) {
        //using two pointers 
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
        //without using two pointers
        while(head!=nullptr){
            if(head->val==INT_MIN) return true;
            head->val=INT_MIN;
            head=head->next;
        }
        return false;
    }
};