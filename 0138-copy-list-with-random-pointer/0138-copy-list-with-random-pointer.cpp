/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* solve(Node* head,unordered_map<Node*,Node*>&um){
    if(head==nullptr){
        return um[nullptr]=nullptr;
    }

    Node* copy=new Node(head->val);
    um[head]=copy;
    if(um.find(head->next)==um.end()){
        copy->next=solve(head->next,um);
    }
    else copy->next=um[head->next];
    if(um.find(head->random)==um.end()){
        copy->random=solve(head->random,um);
    }
    else copy->random=um[head->random];
    return copy;
}
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>um;
        return solve(head,um);
    }
};