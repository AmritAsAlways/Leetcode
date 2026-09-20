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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;
        ListNode *odd=head,*even=head->next,*o=odd,*e=even,*t=even->next;
        bool oddpart=true;
        while(t!=nullptr){
            if(oddpart){
                o->next=t;
                o=o->next;
            }
            else{
                e->next=t;
                e=e->next;
            }
            oddpart=!oddpart;
            t=t->next;
        }
        o->next=even;
        e->next=nullptr;
        return odd;
    }
};