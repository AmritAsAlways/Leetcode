/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int solve(TreeNode* root,int maxi){
    if(root==nullptr) return 0;
    int solution=0;
    if(root->val>=maxi) solution++;

    solution+=solve(root->left,max(maxi,root->val)); 
    solution+=solve(root->right,max(maxi,root->val)); 
    return solution;
}
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        return solve(root,maxi);
    }
};