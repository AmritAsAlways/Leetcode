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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //slight optimized method 
        //first method is to calculate the difference between them and who ever is bigger
        //gets equal by traversing and then they both traverse


        //most optimized method
        ListNode *first=headA,*second=headB;
        while(first!=second){
            first=(first==nullptr) ? first=headB : first=first->next;
            second=(second==nullptr) ? second=headA : second=second->next;
        }
        return first;
    }
};