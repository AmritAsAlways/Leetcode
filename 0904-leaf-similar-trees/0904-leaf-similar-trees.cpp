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
void inorder(TreeNode* root,vector<int>&v){
    if(root==nullptr) return;

    inorder(root->left,v);
    if(root->left==nullptr && root->right==nullptr){
        v.push_back(root->val);
        return;
    }
    inorder(root->right,v);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>first,second;
        inorder(root1,first);
        inorder(root2,second);
        return (first==second) ? true : false;
    }
};
