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
struct comparator{
    bool operator()(ListNode*&a,ListNode*&b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        priority_queue<ListNode*,vector<ListNode*>,comparator>minheap;
        for(int i=0;i<n;i++) if(lists[i]!=nullptr) minheap.push(lists[i]);
        while(!minheap.empty()){
            ListNode* t=minheap.top();
            minheap.pop();

            temp->next=t;
            temp=temp->next;

            if(t->next==nullptr) continue;

            t=t->next;
            minheap.push(t);
        }
        return head->next;
    }
};