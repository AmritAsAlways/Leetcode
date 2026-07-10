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
        ListNode* A=headA,*B=headB;
        bool firsta=true,firstb=true;
        while(A!=B){
            A=A->next;
            B=B->next;
            if(A==nullptr && firsta){
                A=headB;
                firsta=false;
            }
            if(B==nullptr && firstb){
                B=headA;
                firstb=false;
            }
        }
        return A;
    }
};