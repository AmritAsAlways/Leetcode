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
int solve(TreeNode* root,int&answer){
    if(root==nullptr) return 0;

    //lets say the maximum path passes through this root then
    int pathsum=root->val;
    int left=solve(root->left,answer); //it will give the maximal path from it's side
    int right=solve(root->right,answer);
    pathsum+=left+right;

    cout<<pathsum<<" "<<right<<" "<<left<<" "<<root->val<<endl;

    answer=max({answer,pathsum,right+root->val,left+root->val,root->val});
    //and it will also give the most maximal path to its parent
    return max({left+root->val,right+root->val,root->val});
}
    int maxPathSum(TreeNode* root) {
        int answer=INT_MIN;
        solve(root,answer);
        return answer;
    }
};