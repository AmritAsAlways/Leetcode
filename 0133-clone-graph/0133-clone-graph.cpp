/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* solve(Node* node,unordered_map<Node*,Node*>&um){
    if(node==nullptr) return nullptr;
    Node* copy=new Node();
    copy->val=node->val;
    um[node]=copy; //save the copy and the node in a single unit so we can use it
    vector<Node*>v;
    for(int i=0;i<node->neighbors.size();i++){
        if(um.find(node->neighbors[i])==um.end()){
            v.push_back(solve(node->neighbors[i],um));
        }
        else{
            v.push_back(um[node->neighbors[i]]); //here we donot have to create a another node copy that already exits we have to just use the same copy already created by us before and saved 
        }
    }
    copy->neighbors=v;
    return copy;
}
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>um;
        return solve(node,um);
    }
};