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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=prev->next;
        ListNode* ahead=curr->next;
        int firstcriticalpoint=-1,prevcriticalpoint=-1,currentpoint=0;
        int mini=INT_MAX;
        while(ahead!=nullptr){
            if(curr->val>prev->val && curr->val>ahead->val){

                if(firstcriticalpoint==-1){
                    firstcriticalpoint=currentpoint;
                }
                else{
                    mini=min(mini,currentpoint-prevcriticalpoint);
                }

                prevcriticalpoint=currentpoint;
            }
            if(curr->val<prev->val && curr->val<ahead->val){

                if(firstcriticalpoint==-1){
                    firstcriticalpoint=currentpoint;
                }
                else{
                    mini=min(mini,currentpoint-prevcriticalpoint);
                }

                prevcriticalpoint=currentpoint;
            }
            prev=curr;
            curr=ahead;
            ahead=ahead->next;
            currentpoint++;
        }

        if(firstcriticalpoint==-1 || firstcriticalpoint==prevcriticalpoint) return {-1,-1};

        return {mini,prevcriticalpoint-firstcriticalpoint};
    }
};