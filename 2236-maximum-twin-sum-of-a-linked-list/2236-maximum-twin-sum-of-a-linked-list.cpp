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
ListNode* reverse(ListNode* head){
    ListNode *prev=nullptr,*curr=head,*ahead=head->next;
    while(ahead!=nullptr){
        curr->next=prev;
        prev=curr;
        curr=ahead;
        ahead=ahead->next;
    }
    curr->next=prev;
    return curr;
}
    int pairSum(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
            if(fast!=nullptr) fast=fast->next;
        }
        ListNode* t=reverse(slow);
        int answer=INT_MIN;
        while(t!=nullptr){
            answer=max(answer,t->val+head->val);
            head=head->next;
            t=t->next;
        }
        return answer;
    }
};