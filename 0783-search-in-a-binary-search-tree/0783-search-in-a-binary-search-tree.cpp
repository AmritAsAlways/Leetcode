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
TreeNode* solve(TreeNode* root,int val){
    if(root==nullptr) return nullptr;

    if(root->val==val) return root;

    TreeNode* x=solve(root->left,val);
    TreeNode* y=solve(root->right,val);

    if(x!=nullptr) return x;
    if(y!=nullptr) return y;

    return nullptr;
}
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};
